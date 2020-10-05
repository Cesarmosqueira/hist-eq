#pragma once
#include<vector>

namespace CLRCV {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for DisplayHistogram
	/// </summary>
	public ref class DisplayHistogram : public System::Windows::Forms::Form
	{
	public:
		DisplayHistogram(std::vector<int>* _datapoints)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			//rgb_datapoints = nullptr;
			datapoints = new std::vector<int>(_datapoints->begin(), _datapoints->end());
		}
		DisplayHistogram(std::vector<int> R, std::vector<int> G, std::vector<int> B)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			datapoints = nullptr;
			this->R = new vector<int>(R);
			this->G = new vector<int>(G);
			this->B = new vector<int>(B);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DisplayHistogram()
		{
			delete datapoints;
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ mainchart;
	protected: std::vector<int>* datapoints;
	protected: std::vector<int> *R, *G, *B;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	protected:

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
			this->mainchart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mainchart))->BeginInit();
			this->SuspendLayout();
			// 
			// mainchart
			// 
			this->mainchart->Location = System::Drawing::Point(27, 31);
			this->mainchart->Name = L"mainchart";
			this->mainchart->Size = System::Drawing::Size(999, 445);
			this->mainchart->TabIndex = 0;
			this->mainchart->Text = L"Histogram";
			// 
			// groupBox2
			// 
			this->groupBox2->Location = System::Drawing::Point(12, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(1039, 483);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Histogram";
			// 
			// DisplayHistogram
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1063, 507);
			this->Controls->Add(this->mainchart);
			this->Controls->Add(this->groupBox2);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1079, 546);
			this->MinimumSize = System::Drawing::Size(1079, 546);
			this->Name = L"DisplayHistogram";
			this->Text = L"DisplayHistogram";
			this->Load += gcnew System::EventHandler(this, &DisplayHistogram::DisplayHistogram_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mainchart))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void DisplayHistogram_Load(System::Object^ sender, System::EventArgs^ e) {
		System::Windows::Forms::DataVisualization::Charting::ChartArea^ chart_area = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
		System::Windows::Forms::DataVisualization::Charting::Legend^ legend = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
		/*Series*/
		System::Windows::Forms::DataVisualization::Charting::Series^ histogram;
		System::Windows::Forms::DataVisualization::Charting::Series^ Erre, ^Ge, ^Be;
		if (this->datapoints) {
			histogram = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->mainchart->ChartAreas->Add(chart_area);
			legend->Name = L"Legend1";
			this->mainchart->Legends->Add(legend);
			histogram->ChartArea = L"ChartArea1";
			histogram->IsXValueIndexed = true;
			histogram->Legend = L"Legend1";
			histogram->Name = L"Intensity";
			histogram->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::UInt64;
			histogram->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::UInt64;
			System::Windows::Forms::DataVisualization::Charting::DataPoint^ dp;

			for (int i = 0; i < datapoints->size(); i++) {
				dp = gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(i, datapoints->at(i));
				histogram->Points->Add(dp);
			}
			delete dp;
			this->mainchart->Series->Add(histogram);
		}
		else {
			Erre = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			Ge = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			Be = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());

			this->mainchart->ChartAreas->Add(chart_area);
			legend->Name = L"Legend1";
			this->mainchart->Legends->Add(legend);
			Erre->ChartArea = L"ChartArea1";
			Erre->IsXValueIndexed = true;
			Erre->Legend = L"Legend1";
			Erre->Name = L"Red Intensity";
			Erre->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::UInt64;
			Erre->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::UInt64;

			Ge->ChartArea = L"ChartArea1";
			Ge->IsXValueIndexed = true;
			Ge->Legend = L"Legend1";
			Ge->Name = L"Green Intensity";
			Ge->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::UInt64;
			Ge->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::UInt64;

			Be->ChartArea = L"ChartArea1";
			Be->IsXValueIndexed = true;
			Be->Legend = L"Legend1";
			Be->Name = L"Blue Intensity";
			Be->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::UInt64;
			Be->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::UInt64;

			System::Windows::Forms::DataVisualization::Charting::DataPoint^ dp;
			System::Windows::Forms::DataVisualization::Charting::DataPoint ^dpR, ^dpG, ^dpB;
			for (int i = 0; i < R->size(); i++) {
				dpR = gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(i, R->at(i));
				dpG = gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(i, G->at(i));
				dpB = gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(i, B->at(i));
				Erre->Points->Add(dpR);
				Ge->Points->Add(dpG);
				Be->Points->Add(dpB);
			}
			Erre->Color = Color::Red;
			Ge->Color = Color::Green;
			Be->Color = Color::Blue;
			this->mainchart->Series->Add(Erre);
			this->mainchart->Series->Add(Ge);
			this->mainchart->Series->Add(Be);
		}
	}
	};
}
