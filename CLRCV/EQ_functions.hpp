#pragma once
#include<opencv2/opencv.hpp>
#include <msclr\marshal_cppstd.h>
#include <string>
#include<vector>
using namespace System::Drawing;
using namespace cv;
using namespace std;

std::vector<int> get_pixel_freq(const Mat& img) { //O(n^2)
	std::vector<int> freq(256, 0);  // [0,0,0,0,0]
	for (int i = 0; i < img.rows; i++) {     
		for (int j = 0; j < img.cols; j++) {
			freq[img.at<uchar>(i, j)] += 1;
		}
	}
	return freq;
}
float round_this(const float& var)
{
	float value = (int)(var * 100 + .5);
	return (float)value / 100;
}
std::vector<float> get_new_positions(std::vector<int> freq, const int& pixel_density) { //O(n)
	std::vector<float> positions(256, 0); //s(k)
	positions[0] = freq[0]; 

	for (int i = 1; i < freq.size() + 1; i++) { 
		if (i != freq.size()) { //accumulating frequencies 
			positions[i] = freq[i] + positions[i-1];
		}
		positions[i - 1] = (positions[i-1]/ pixel_density)*255;
	}
	return positions;
}
std::vector<int> make_histogram(const std::vector<float>& new_positions, 
	const std::vector<int>& original_pfreq, const int& p_dens) {
	
	std::vector<int> histogram(256, 0);
	for (int i = 0; i < original_pfreq.size(); i++) {
		histogram[new_positions[i]] = original_pfreq[i];
	}
	return histogram;
}	
Mat transform_mat(cv::Mat dst, const vector<int>& new_hist) {
	int width = dst.cols, height = dst.rows; 
	int a = 0;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			dst.at<uchar>(y, x) = new_hist[dst.at<uchar>(y, x)]; //[0...255]
		}
	}
	return dst;
}
void eq_histogram(Mat src, Mat& dst, std::vector<int>*% update_hist_p, std::vector<int>*% update_hist_r) {
	std::vector<int> pixel_frequency = get_pixel_freq(src); // [10, 100, 23 .... 10]
	update_hist_p = new vector<int>(pixel_frequency); //
	std::vector<float> pos = get_new_positions(pixel_frequency, src.rows * src.cols);
	std::vector<int> new_histogram = make_histogram(pos, pixel_frequency, src.rows*src.cols);
	dst = transform_mat(src, new_histogram);
	update_hist_r = new vector<int>(new_histogram); //
}

void histEQ(System::String^ path, std::vector<int>*% update_hist_p, std::vector<int>*% update_hist_r, int times) {
	cv::Mat img, src;
	msclr::interop::marshal_context context;
	src = imread(context.marshal_as<std::string>(path));
	eq_histogram(src, img, update_hist_p, update_hist_r);
	equalizeHist(imread(context.marshal_as<std::string>(path), 0), img);
	string out = "img\\outputs\\output";
	out += times + 48;
	out.append(".jpg");
	imwrite(out, img);
}

struct vec3 {
	int r, g, b;
	vec3(const int&r, const int&g, const int% b) {
		this->r = r;
		this->g = g;
		this->b = b;
	}
	void addR() { r++; }
	void addG() { g++; }
	void addB() { b++; }
};

vector<int>* get_rgb_histograms(const std::string& path) {
	vector<int>* hist = new vector<int>[3];
	hist[0] = vector<int>(256, 0);
	hist[1] = vector<int>(256, 0);
	hist[2] = vector<int>(256, 0);
	Mat original = imread(path);
	for (int i = 0; i < original.rows; i++) {
		for (int j = 0; j < original.cols; j++) {
			hist[0].at(original.at<Vec3b>(i, j)[0]) += 1;
			hist[1].at(original.at<Vec3b>(i, j)[1]) += 1;
			hist[2].at(original.at<Vec3b>(i, j)[2]) += 1;
		}
	}
	return hist;
}
vector<int> expand_vect(vector<int> arr) {
	int l = 1, r = 255;
	int min = 1, max = 255;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] != 0) {
			l = i;
			break;
		}
	}
	for (int i = arr.size() - 1; 0 <= i; i--) {
		if (arr[i] != 0) {
			r = i;
			break;
		}
	}
	double weight = (float)254 / 63;
	int bias = 1 - (weight * l);

	/*map new vector*/
	vector<int> pos(256,0);
	for (int i = 0; i < arr.size(); i++) {
		pos[i] = (int)(weight * arr[i]) + (int)bias;
		if (pos[i] < 0) pos[i] = 0;
		if (pos[i] > 255) pos[i] = 255;
		cout << "(" << weight << "*" << arr[i] << ") + " << bias << " = " << pos[i] << "\n";
	}
	vector<int> expanded(256, 0);
	for (int i = 0; i < arr.size(); i++) {
		if (pos[i] < 0) pos[i] = 0;
		if (pos[i] > 255) pos[i] = 255;
		expanded[pos[i]] += arr[i];
	}
	return expanded;
}
vector<int> expand_on_path(const string& path, vector<int> histogram, int times) {
	Mat img = imread(path);
	vector<int> expanded_hist = expand_vect(histogram);
	/*transform*/
	string out = "img\\outputs\\output";
	out += times + 48;
	out.append(".jpg");
	imwrite(out, img);
	return expanded_hist;
}

vector<int> get_grayscale_histogram(const std::string& path) {
	vector<int> hist(256, 0);
	Mat original = imread(path);
	for (int i = 0; i < original.rows; i++) {
		for (int j = 0; j < original.cols; j++) {
			hist[int(original.at<uchar>(i, j))]++;
		}
	}
	return hist;
}

void equalizeIntensity(const Mat& inputImage, int times)
{
	if (inputImage.channels() >= 3)
	{
		Mat ycrcb;

		cvtColor(inputImage, ycrcb, CV_BGR2YCrCb);

		vector<Mat> channels;
		split(ycrcb, channels);

		equalizeHist(channels[0], channels[0]);

		Mat result;
		merge(channels, ycrcb);

		cvtColor(ycrcb, result, CV_YCrCb2BGR);
		string out = "img\\outputs\\output";
		out += times + 48;
		out.append(".jpg");
		imwrite(out, ycrcb);
	}
}


