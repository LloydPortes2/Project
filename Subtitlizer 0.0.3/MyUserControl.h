#pragma once
#include <iostream>
#include <string>
#include <windows.h>


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Subtitlizer003 {

	/// <summary>
	/// Summary for MyUserControl
	/// </summary>
	public ref class MyUserControl : public System::Windows::Forms::UserControl
	{
	public:
		MyUserControl(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyUserControl()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ txt_bx;
	protected:
	private: System::Windows::Forms::Button^ search_btn;
	private: System::Windows::Forms::Button^ export_btn;
	private: System::Windows::Forms::ComboBox^ intput_lng_cb;
	private: System::Windows::Forms::ComboBox^ output_lng_cb;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::Label^ input_lng_txt;
	private: System::Windows::Forms::Label^ output_lng_txt;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::VScrollBar^ vScrollBar1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->txt_bx = (gcnew System::Windows::Forms::TextBox());
			this->search_btn = (gcnew System::Windows::Forms::Button());
			this->export_btn = (gcnew System::Windows::Forms::Button());
			this->intput_lng_cb = (gcnew System::Windows::Forms::ComboBox());
			this->output_lng_cb = (gcnew System::Windows::Forms::ComboBox());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->input_lng_txt = (gcnew System::Windows::Forms::Label());
			this->output_lng_txt = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->vScrollBar1 = (gcnew System::Windows::Forms::VScrollBar());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// txt_bx
			// 
			this->txt_bx->Location = System::Drawing::Point(161, 37);
			this->txt_bx->Name = L"txt_bx";
			this->txt_bx->Size = System::Drawing::Size(549, 20);
			this->txt_bx->TabIndex = 0;
			// 
			// search_btn
			// 
			this->search_btn->Location = System::Drawing::Point(39, 35);
			this->search_btn->Name = L"search_btn";
			this->search_btn->Size = System::Drawing::Size(75, 23);
			this->search_btn->TabIndex = 1;
			this->search_btn->Text = L"Search File";
			this->search_btn->UseVisualStyleBackColor = true;
			this->search_btn->Click += gcnew System::EventHandler(this, &MyUserControl::search_btn_Click);
			// 
			// export_btn
			// 
			this->export_btn->Location = System::Drawing::Point(716, 494);
			this->export_btn->Name = L"export_btn";
			this->export_btn->Size = System::Drawing::Size(144, 85);
			this->export_btn->TabIndex = 2;
			this->export_btn->Text = L"Export";
			this->export_btn->UseVisualStyleBackColor = true;
			this->export_btn->Click += gcnew System::EventHandler(this, &MyUserControl::export_btn_Click);
			// 
			// intput_lng_cb
			// 
			this->intput_lng_cb->FormattingEnabled = true;
			this->intput_lng_cb->Location = System::Drawing::Point(739, 61);
			this->intput_lng_cb->Name = L"intput_lng_cb";
			this->intput_lng_cb->Size = System::Drawing::Size(121, 21);
			this->intput_lng_cb->TabIndex = 3;
			// 
			// output_lng_cb
			// 
			this->output_lng_cb->FormattingEnabled = true;
			this->output_lng_cb->Location = System::Drawing::Point(739, 314);
			this->output_lng_cb->Name = L"output_lng_cb";
			this->output_lng_cb->Size = System::Drawing::Size(121, 21);
			this->output_lng_cb->TabIndex = 4;
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(39, 535);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(671, 23);
			this->progressBar1->TabIndex = 5;
			this->progressBar1->Click += gcnew System::EventHandler(this, &MyUserControl::progressBar1_Click);
			// 
			// input_lng_txt
			// 
			this->input_lng_txt->AutoSize = true;
			this->input_lng_txt->Location = System::Drawing::Point(736, 40);
			this->input_lng_txt->Name = L"input_lng_txt";
			this->input_lng_txt->Size = System::Drawing::Size(82, 13);
			this->input_lng_txt->TabIndex = 6;
			this->input_lng_txt->Text = L"Input Language";
			// 
			// output_lng_txt
			// 
			this->output_lng_txt->AutoSize = true;
			this->output_lng_txt->Location = System::Drawing::Point(739, 295);
			this->output_lng_txt->Name = L"output_lng_txt";
			this->output_lng_txt->Size = System::Drawing::Size(90, 13);
			this->output_lng_txt->TabIndex = 7;
			this->output_lng_txt->Text = L"Output Language";
			this->output_lng_txt->Click += gcnew System::EventHandler(this, &MyUserControl::label1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(39, 78);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(671, 435);
			this->textBox1->TabIndex = 8;
			// 
			// vScrollBar1
			// 
			this->vScrollBar1->Location = System::Drawing::Point(689, 78);
			this->vScrollBar1->Name = L"vScrollBar1";
			this->vScrollBar1->Size = System::Drawing::Size(21, 435);
			this->vScrollBar1->TabIndex = 9;
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyUserControl::timer1_Tick);
			// 
			// MyUserControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->vScrollBar1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->output_lng_txt);
			this->Controls->Add(this->input_lng_txt);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->output_lng_cb);
			this->Controls->Add(this->intput_lng_cb);
			this->Controls->Add(this->export_btn);
			this->Controls->Add(this->search_btn);
			this->Controls->Add(this->txt_bx);
			this->Name = L"MyUserControl";
			this->Size = System::Drawing::Size(875, 596);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void search_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	OPENFILENAME ofn;


	// a another memory buffer to contain the file name
	char szFile[100];
	// open a file name
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;
	ofn.lpstrFile = L"szFile";
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = L"Video Files (*.avi;*.mp4;*.mkv)\0*.avi;*.mp4;*.mkv\0All Files (*.*)\0*.*\0";

	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	GetOpenFileName(&ofn);
}
private: System::Void progressBar1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	progressBar1->Increment(1);
	if (progressBar1->Value == 100)//prototype purposes
	{
		timer1->Stop();

		progressBar1->Value = 0;
	}
}
private: System::Void export_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	timer1->Start(); //for prototype purposes
}

};

}
