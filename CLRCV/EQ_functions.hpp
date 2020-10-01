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
	cout << "Equalized:\n";
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

void histEQ(System::String^ path, std::vector<int>*% update_hist_p, std::vector<int>*% update_hist_r) {
	cv::Mat img, src;
	msclr::interop::marshal_context context;
	src = imread(context.marshal_as<std::string>(path));
	eq_histogram(src, img, update_hist_p, update_hist_r);
	equalizeHist(imread(context.marshal_as<std::string>(path), 0), img);
	imwrite("img\\output1.jpg", img);
}
