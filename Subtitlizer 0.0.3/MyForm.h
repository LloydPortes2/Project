#pragma once
#include <iostream>
#include <string>
#include <msclr\marshal_cppstd.h>
#include <windows.h>

namespace Subtitlizer003 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^ console;

	protected:

	private: System::Windows::Forms::Label^ output_lng_txt;
	private: System::Windows::Forms::Label^ input_lng_txt;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::ComboBox^ output_lng_cb;
	private: System::Windows::Forms::ComboBox^ intput_lng_cb;
	private: System::Windows::Forms::Button^ export_btn;
	private: System::Windows::Forms::Button^ search_btn;
	private: System::Windows::Forms::TextBox^ txt_bx;
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
			this->console = (gcnew System::Windows::Forms::TextBox());
			this->output_lng_txt = (gcnew System::Windows::Forms::Label());
			this->input_lng_txt = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->output_lng_cb = (gcnew System::Windows::Forms::ComboBox());
			this->intput_lng_cb = (gcnew System::Windows::Forms::ComboBox());
			this->export_btn = (gcnew System::Windows::Forms::Button());
			this->search_btn = (gcnew System::Windows::Forms::Button());
			this->txt_bx = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// console
			// 
			this->console->Location = System::Drawing::Point(32, 52);
			this->console->Multiline = true;
			this->console->Name = L"console";
			this->console->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->console->Size = System::Drawing::Size(671, 435);
			this->console->TabIndex = 18;
			this->console->TextChanged += gcnew System::EventHandler(this, &MyForm::console_Changed);
			// 
			// output_lng_txt
			// 
			this->output_lng_txt->AutoSize = true;
			this->output_lng_txt->Location = System::Drawing::Point(732, 269);
			this->output_lng_txt->Name = L"output_lng_txt";
			this->output_lng_txt->Size = System::Drawing::Size(90, 13);
			this->output_lng_txt->TabIndex = 17;
			this->output_lng_txt->Text = L"Output Language";
			// 
			// input_lng_txt
			// 
			this->input_lng_txt->AutoSize = true;
			this->input_lng_txt->Location = System::Drawing::Point(729, 14);
			this->input_lng_txt->Name = L"input_lng_txt";
			this->input_lng_txt->Size = System::Drawing::Size(82, 13);
			this->input_lng_txt->TabIndex = 16;
			this->input_lng_txt->Text = L"Input Language";
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(32, 509);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(671, 23);
			this->progressBar1->TabIndex = 15;
			this->progressBar1->Click += gcnew System::EventHandler(this, &MyForm::progressBar1_Click);
			// 
			// output_lng_cb
			// 
			this->output_lng_cb->FormattingEnabled = true;
			this->output_lng_cb->Location = System::Drawing::Point(732, 288);
			this->output_lng_cb->Name = L"output_lng_cb";
			this->output_lng_cb->Size = System::Drawing::Size(121, 21);
			this->output_lng_cb->TabIndex = 14;
			// 
			// intput_lng_cb
			// 
			this->intput_lng_cb->FormattingEnabled = true;
			this->intput_lng_cb->Location = System::Drawing::Point(732, 35);
			this->intput_lng_cb->Name = L"intput_lng_cb";
			this->intput_lng_cb->Size = System::Drawing::Size(121, 21);
			this->intput_lng_cb->TabIndex = 13;
			// 
			// export_btn
			// 
			this->export_btn->Location = System::Drawing::Point(709, 468);
			this->export_btn->Name = L"export_btn";
			this->export_btn->Size = System::Drawing::Size(144, 85);
			this->export_btn->TabIndex = 12;
			this->export_btn->Text = L"Export";
			this->export_btn->UseVisualStyleBackColor = true;
			this->export_btn->Click += gcnew System::EventHandler(this, &MyForm::export_btn_Click);
			// 
			// search_btn
			// 
			this->search_btn->Location = System::Drawing::Point(32, 9);
			this->search_btn->Name = L"search_btn";
			this->search_btn->Size = System::Drawing::Size(75, 23);
			this->search_btn->TabIndex = 11;
			this->search_btn->Text = L"Search File";
			this->search_btn->UseVisualStyleBackColor = true;
			this->search_btn->Click += gcnew System::EventHandler(this, &MyForm::search_btn_Click);
			// 
			// txt_bx
			// 
			this->txt_bx->AccessibleRole = System::Windows::Forms::AccessibleRole::Text;
			this->txt_bx->CausesValidation = false;
			this->txt_bx->HideSelection = false;
			this->txt_bx->Location = System::Drawing::Point(154, 11);
			this->txt_bx->Name = L"txt_bx";
			this->txt_bx->Size = System::Drawing::Size(549, 20);
			this->txt_bx->TabIndex = 10;
			this->txt_bx->TextChanged += gcnew System::EventHandler(this, &MyForm::txt_bx_TextChanged);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(881, 567);
			this->Controls->Add(this->console);
			this->Controls->Add(this->output_lng_txt);
			this->Controls->Add(this->input_lng_txt);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->output_lng_cb);
			this->Controls->Add(this->intput_lng_cb);
			this->Controls->Add(this->export_btn);
			this->Controls->Add(this->search_btn);
			this->Controls->Add(this->txt_bx);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private:
	System::String^ selectedFilePath;

private: System::Void search_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	//Holds characters in an array and the max amount of characters it can hold is the file path
	WCHAR buffer[MAX_PATH];
	//Opens a file and is named as ofn
	OPENFILENAME ofn = {};
	//This line sets the size of the OPENFILENAME structure in bytes.
	ofn.lStructSize = sizeof(ofn);
	//Specifies what format to be searched
	ofn.lpstrFilter = L"Video Files (*.avi;*.mp4;*.mkv)\0*.avi;*.mp4;*.mkv\0All Files (*.*)\0*.*\0";
	//When the windows explorer is opened, the user can only pick the specifed formats in the windows explorer
	ofn.lpstrFile = buffer, ofn.nMaxFile = MAX_PATH, * buffer = '\0';
	//When the windows explorer is opened
	ofn.Flags = OFN_EXPLORER | OFN_ENABLESIZING | OFN_HIDEREADONLY | OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	
	//This line calls the GetOpenFileName function, passing the address of the OPENFILENAME structure as an argument. If the function returns a non-zero value, it 
	//indicates that the user selected a file and the dialog box was closed.
	if (GetOpenFileName(&ofn)) {
		//his line creates a new System::String object and initializes it with the contents of the "buffer" array. 
		//The "selectedFilePath" variable is then set to the new string
		selectedFilePath = gcnew System::String(buffer);
		txt_bx->Text = selectedFilePath;
	}
	}
private: System::Void console_Changed(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void progressBar1_Click(System::Object^ sender, System::EventArgs^ e) {
	timer1->Stop();

	progressBar1->Value = 0;
}
private: System::Void export_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	timer1->Start(); //for prototype purposes
}
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	progressBar1->Increment(1);
	if (progressBar1->Value == 100)//prototype purposes
	{
		timer1->Stop();

		progressBar1->Value = 0;
	}
}
private: System::Void txt_bx_TextChanged(System::Object^ sender, System::EventArgs^ e) {


}
};
}
