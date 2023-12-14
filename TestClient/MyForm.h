#pragma once

namespace TestClient {

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
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ IP_to_conect_textbox;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ directory_contents_textbox;
	private: System::Windows::Forms::ComboBox^ file_type_comboBox;


	private: System::Windows::Forms::TextBox^ directory_path_textbox;
	private: System::Windows::Forms::Button^ retrive_files_button;


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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->IP_to_conect_textbox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->directory_contents_textbox = (gcnew System::Windows::Forms::TextBox());
			this->file_type_comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->directory_path_textbox = (gcnew System::Windows::Forms::TextBox());
			this->retrive_files_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(51, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(116, 46);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Підключитись до сервера";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// IP_to_conect_textbox
			// 
			this->IP_to_conect_textbox->Location = System::Drawing::Point(262, 26);
			this->IP_to_conect_textbox->Name = L"IP_to_conect_textbox";
			this->IP_to_conect_textbox->Size = System::Drawing::Size(198, 20);
			this->IP_to_conect_textbox->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(225, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(21, 15);
			this->label1->TabIndex = 2;
			this->label1->Text = L"IP:";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// directory_contents_textbox
			// 
			this->directory_contents_textbox->Location = System::Drawing::Point(31, 65);
			this->directory_contents_textbox->Multiline = true;
			this->directory_contents_textbox->Name = L"directory_contents_textbox";
			this->directory_contents_textbox->Size = System::Drawing::Size(526, 300);
			this->directory_contents_textbox->TabIndex = 3;
			// 
			// file_type_comboBox
			// 
			this->file_type_comboBox->FormattingEnabled = true;
			this->file_type_comboBox->Location = System::Drawing::Point(31, 406);
			this->file_type_comboBox->Name = L"file_type_comboBox";
			this->file_type_comboBox->Size = System::Drawing::Size(127, 21);
			this->file_type_comboBox->TabIndex = 4;
			// 
			// directory_path_textbox
			// 
			this->directory_path_textbox->Location = System::Drawing::Point(228, 406);
			this->directory_path_textbox->Name = L"directory_path_textbox";
			this->directory_path_textbox->Size = System::Drawing::Size(273, 20);
			this->directory_path_textbox->TabIndex = 5;
			this->directory_path_textbox->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// retrive_files_button
			// 
			this->retrive_files_button->Location = System::Drawing::Point(539, 395);
			this->retrive_files_button->Name = L"retrive_files_button";
			this->retrive_files_button->Size = System::Drawing::Size(93, 40);
			this->retrive_files_button->TabIndex = 6;
			this->retrive_files_button->Text = L"Знайти файли";
			this->retrive_files_button->UseVisualStyleBackColor = true;
			this->retrive_files_button->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(644, 478);
			this->Controls->Add(this->retrive_files_button);
			this->Controls->Add(this->directory_path_textbox);
			this->Controls->Add(this->file_type_comboBox);
			this->Controls->Add(this->directory_contents_textbox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->IP_to_conect_textbox);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
