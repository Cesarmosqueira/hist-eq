#pragma once
#include "DisplayHistogram.h"
#include "EQ_functions.hpp"
namespace CLRCV {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Summary for Display
	/// </summary>
	public ref class Display : public System::Windows::Forms::Form
	{
	public:
		Display(void)
		{
			prev_hist = res_hist = nullptr;
			rgb_prev_hist = new vector<int>[3];
			rgb_res_hist = new vector<int>[3];
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			times_pressed = 0;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Display()
		{
			delete prev_hist, res_hist;
			delete[] rgb_prev_hist, rgb_res_hist;
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ dstPanel;
	protected:
	private: std::vector<int>* prev_hist, *res_hist;
	private: std::vector<int>* rgb_prev_hist, * rgb_res_hist;
	private: System::Windows::Forms::GroupBox^ Result;
	private: System::Windows::Forms::GroupBox^ Preview;
	private: System::Windows::Forms::Panel^ srcPanel;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ examinate;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ image_path;
	private: System::Windows::Forms::ComboBox^ configsBX;
	private: System::Windows::Forms::Button^ processBtn;
	private: System::Windows::Forms::OpenFileDialog^ dialogFile;

	private: System::Windows::Forms::Button^ hist_res;
	private: System::Windows::Forms::Button^ hist_prev;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Drawing::Bitmap^ dstBoxbmp;
	private: int times_pressed;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Display::typeid));
			this->dstPanel = (gcnew System::Windows::Forms::Panel());
			this->hist_res = (gcnew System::Windows::Forms::Button());
			this->Result = (gcnew System::Windows::Forms::GroupBox());
			this->Preview = (gcnew System::Windows::Forms::GroupBox());
			this->srcPanel = (gcnew System::Windows::Forms::Panel());
			this->hist_prev = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->examinate = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->image_path = (gcnew System::Windows::Forms::TextBox());
			this->configsBX = (gcnew System::Windows::Forms::ComboBox());
			this->processBtn = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->dialogFile = (gcnew System::Windows::Forms::OpenFileDialog());
			this->dstPanel->SuspendLayout();
			this->Result->SuspendLayout();
			this->Preview->SuspendLayout();
			this->srcPanel->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dstPanel
			// 
			this->dstPanel->Controls->Add(this->hist_res);
			this->dstPanel->Location = System::Drawing::Point(9, 19);
			this->dstPanel->Name = L"dstPanel";
			this->dstPanel->Size = System::Drawing::Size(386, 291);
			this->dstPanel->TabIndex = 1;
			// 
			// hist_res
			// 
			this->hist_res->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"hist_res.Image")));
			this->hist_res->Location = System::Drawing::Point(3, 4);
			this->hist_res->Name = L"hist_res";
			this->hist_res->Size = System::Drawing::Size(26, 24);
			this->hist_res->TabIndex = 1;
			this->hist_res->UseVisualStyleBackColor = true;
			this->hist_res->Click += gcnew System::EventHandler(this, &Display::hist_res_Click);
			// 
			// Result
			// 
			this->Result->Controls->Add(this->dstPanel);
			this->Result->Location = System::Drawing::Point(613, 7);
			this->Result->Name = L"Result";
			this->Result->Size = System::Drawing::Size(407, 316);
			this->Result->TabIndex = 2;
			this->Result->TabStop = false;
			this->Result->Text = L"Result";
			// 
			// Preview
			// 
			this->Preview->Controls->Add(this->srcPanel);
			this->Preview->Location = System::Drawing::Point(12, 7);
			this->Preview->Name = L"Preview";
			this->Preview->Size = System::Drawing::Size(407, 316);
			this->Preview->TabIndex = 3;
			this->Preview->TabStop = false;
			this->Preview->Text = L"Preview";
			// 
			// srcPanel
			// 
			this->srcPanel->Controls->Add(this->hist_prev);
			this->srcPanel->Location = System::Drawing::Point(9, 19);
			this->srcPanel->Name = L"srcPanel";
			this->srcPanel->Size = System::Drawing::Size(386, 291);
			this->srcPanel->TabIndex = 1;
			// 
			// hist_prev
			// 
			this->hist_prev->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"hist_prev.Image")));
			this->hist_prev->Location = System::Drawing::Point(357, 3);
			this->hist_prev->Name = L"hist_prev";
			this->hist_prev->Size = System::Drawing::Size(26, 24);
			this->hist_prev->TabIndex = 0;
			this->hist_prev->UseVisualStyleBackColor = true;
			this->hist_prev->Click += gcnew System::EventHandler(this, &Display::hist_prev_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->examinate);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->image_path);
			this->groupBox1->Controls->Add(this->configsBX);
			this->groupBox1->Controls->Add(this->processBtn);
			this->groupBox1->Controls->Add(this->groupBox2);
			this->groupBox1->Location = System::Drawing::Point(425, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(182, 312);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Tools";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(15, 194);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 6;
			this->button1->Text = L"RGB";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Display::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(17, 104);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(69, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Configuration";
			// 
			// examinate
			// 
			this->examinate->Location = System::Drawing::Point(128, 46);
			this->examinate->Name = L"examinate";
			this->examinate->Size = System::Drawing::Size(29, 23);
			this->examinate->TabIndex = 4;
			this->examinate->Text = L"...";
			this->examinate->UseVisualStyleBackColor = true;
			this->examinate->Click += gcnew System::EventHandler(this, &Display::examinate_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(17, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(73, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Source Image";
			// 
			// image_path
			// 
			this->image_path->Location = System::Drawing::Point(17, 48);
			this->image_path->Name = L"image_path";
			this->image_path->ReadOnly = true;
			this->image_path->Size = System::Drawing::Size(105, 20);
			this->image_path->TabIndex = 2;
			// 
			// configsBX
			// 
			this->configsBX->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->configsBX->FormattingEnabled = true;
			this->configsBX->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Equalize", L"Expand " });
			this->configsBX->Location = System::Drawing::Point(20, 123);
			this->configsBX->Name = L"configsBX";
			this->configsBX->Size = System::Drawing::Size(137, 21);
			this->configsBX->TabIndex = 1;
			// 
			// processBtn
			// 
			this->processBtn->Location = System::Drawing::Point(96, 194);
			this->processBtn->Name = L"processBtn";
			this->processBtn->Size = System::Drawing::Size(75, 23);
			this->processBtn->TabIndex = 0;
			this->processBtn->Text = L"Grayscale";
			this->processBtn->UseVisualStyleBackColor = true;
			this->processBtn->Click += gcnew System::EventHandler(this, &Display::processBtn_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Location = System::Drawing::Point(6, 168);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(170, 69);
			this->groupBox2->TabIndex = 7;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Process";
			// 
			// dialogFile
			// 
			this->dialogFile->InitialDirectory = L"$(ProjectDir)img";
			// 
			// Display
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1032, 336);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->Preview);
			this->Controls->Add(this->Result);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1048, 375);
			this->MinimumSize = System::Drawing::Size(1048, 375);
			this->Name = L"Display";
			this->Text = L"Display";
			this->Load += gcnew System::EventHandler(this, &Display::Display_Load);
			this->dstPanel->ResumeLayout(false);
			this->Result->ResumeLayout(false);
			this->Preview->ResumeLayout(false);
			this->srcPanel->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void examinate_Click(System::Object^ sender, System::EventArgs^ e) {
	
	dialogFile->Title = "Select an image";
	dialogFile->ShowDialog();
	image_path->Text = dialogFile->FileName;
	
}
private: System::Void Display_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void processBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	prev_hist = nullptr;
	res_hist = nullptr;
	srcPanel->CreateGraphics()->Clear(srcPanel->BackColor);
	dstPanel->CreateGraphics()->Clear(dstPanel->BackColor);
	if (configsBX->SelectedIndex == 0) { //Equalize
		rgb_prev_hist = rgb_res_hist = nullptr;
		times_pressed++;
		srcPanel->CreateGraphics()->DrawImage(gcnew Bitmap(image_path->Text), srcPanel->ClientRectangle);
		histEQ(image_path->Text, prev_hist, res_hist, times_pressed);
		string out = "img\\outputs\\output";
		out += times_pressed+ 48;
		out.append(".jpg");
		dstBoxbmp = gcnew Bitmap(gcnew System::String(out.c_str()));
        dstPanel->CreateGraphics()->DrawImage(dstBoxbmp, dstPanel->ClientRectangle);
	}
	else if (configsBX->SelectedIndex == 1) {
		rgb_prev_hist = rgb_res_hist = nullptr;
		times_pressed++;
		srcPanel->CreateGraphics()->DrawImage(gcnew Bitmap(image_path->Text), srcPanel->ClientRectangle);
		msclr::interop::marshal_context context;
		string s = context.marshal_as<std::string>(image_path->Text);
		/*load histogram prev*/
		prev_hist = new vector<int>(get_grayscale_histogram(s));
		
		/*expand*/
		res_hist = new vector<int>(expand_on_path(s, *prev_hist, times_pressed));

		string out = "img\\outputs\\output";
		out += times_pressed + 48;
		out.append(".jpg");
		dstBoxbmp = gcnew Bitmap(gcnew System::String(out.c_str()));
		dstPanel->CreateGraphics()->DrawImage(dstBoxbmp, dstPanel->ClientRectangle);
		/*load out histogram*/
	}
}
private: System::Void hist_prev_Click(System::Object^ sender, System::EventArgs^ e) {
	if (prev_hist) {
		DisplayHistogram^ f = gcnew DisplayHistogram(prev_hist);
		f->ShowDialog();
	}
	else if (rgb_prev_hist) {
		DisplayHistogram^ f = gcnew DisplayHistogram(rgb_prev_hist[0], rgb_prev_hist[1], rgb_prev_hist[1]);
		f->ShowDialog();
	}
}
private: System::Void hist_res_Click(System::Object^ sender, System::EventArgs^ e) {
	if (res_hist) {
		DisplayHistogram^ f = gcnew DisplayHistogram(res_hist);
		f->ShowDialog();
	}
	else if (rgb_res_hist) {
		DisplayHistogram^ f = gcnew DisplayHistogram(rgb_res_hist[0], rgb_res_hist[1], rgb_res_hist[1]);
		f->ShowDialog();
	}
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	rgb_prev_hist[0].clear(); // R
	rgb_prev_hist[1].clear(); // G
	rgb_prev_hist[2].clear(); // B
	srcPanel->CreateGraphics()->Clear(srcPanel->BackColor);
	dstPanel->CreateGraphics()->Clear(dstPanel->BackColor);
	if (configsBX->SelectedIndex == 0) { //Equalize
		prev_hist = nullptr;
		res_hist = nullptr;
		times_pressed++;
		srcPanel->CreateGraphics()->DrawImage(gcnew Bitmap(image_path->Text), srcPanel->ClientRectangle);
		msclr::interop::marshal_context context;
		string s = context.marshal_as<std::string>(image_path->Text);
		delete[] rgb_prev_hist;
		rgb_prev_hist = get_rgb_histograms(s);
		equalizeIntensity(imread(s), times_pressed);
		string out = "img\\outputs\\output";
		out += times_pressed + 48;
		out.append(".jpg");
		dstBoxbmp = gcnew Bitmap(gcnew System::String(out.c_str()));
		dstPanel->CreateGraphics()->DrawImage(dstBoxbmp, dstPanel->ClientRectangle);
		rgb_res_hist = get_rgb_histograms(out);
	}
	else if (configsBX->SelectedIndex == 1) { //Equalize
		prev_hist = nullptr;
		res_hist = nullptr;
		times_pressed++;
		srcPanel->CreateGraphics()->DrawImage(gcnew Bitmap(image_path->Text), srcPanel->ClientRectangle);
		msclr::interop::marshal_context context;
		string s = context.marshal_as<std::string>(image_path->Text);
		delete[] rgb_prev_hist;
		rgb_prev_hist = get_rgb_histograms(s);
		/*expand*/

		string out = "img\\outputs\\output";
		out += times_pressed + 48;
		out.append(".jpg");
		dstBoxbmp = gcnew Bitmap(gcnew System::String(out.c_str()));
		dstPanel->CreateGraphics()->DrawImage(dstBoxbmp, dstPanel->ClientRectangle);
		rgb_res_hist = get_rgb_histograms(out);
	}
}
};
}
