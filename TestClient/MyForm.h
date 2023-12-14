#include <iostream>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <msclr/marshal_cppstd.h>
#pragma comment(lib, "ws2_32.lib")

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

	const int PORT = 12345;  // Use the same port as the server
	//const char* SERVER_IP = NULL;  // Replace with the server's IP address
	SOCKET clientSocket;

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
			this->label1->Size = System::Drawing::Size(20, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"IP:";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// directory_contents_textbox
			// 
			this->directory_contents_textbox->Location = System::Drawing::Point(31, 65);
			this->directory_contents_textbox->Multiline = true;
			this->directory_contents_textbox->Name = L"directory_contents_textbox";
			this->directory_contents_textbox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
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
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		WSADATA wsaData;
		if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
			directory_contents_textbox->Text = L"WSAStartup failed.";
			return;
		}

		clientSocket = socket(AF_INET, SOCK_STREAM, 0);
		if (clientSocket == INVALID_SOCKET) {
			directory_contents_textbox->Text = L"Error at socket(): " + WSAGetLastError();
			WSACleanup();
			return;
		}

		sockaddr_in serverAddr;
		serverAddr.sin_family = AF_INET;
		serverAddr.sin_port = htons(PORT);
		System::String^ SERVER_IP_FORMS = IP_to_conect_textbox->Text;
		std::string serverIpStdString = msclr::interop::marshal_as<std::string>(SERVER_IP_FORMS);
		const char* SERVER_IP = serverIpStdString.c_str();
		inet_pton(AF_INET, SERVER_IP, &serverAddr.sin_addr);

		if (connect(clientSocket, reinterpret_cast<SOCKADDR*>(&serverAddr), sizeof(serverAddr)) == SOCKET_ERROR) {
			directory_contents_textbox->Text = L"Failed to connect to server: " + WSAGetLastError();
			closesocket(clientSocket);
			WSACleanup();
			return;
		}

		directory_contents_textbox->Text += "Connected to the server.";
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		std::string directoryPath;
		System::String^ directoryPathForms = directory_path_textbox->Text;
		directoryPath = msclr::interop::marshal_as<std::string>(directoryPathForms);
		std::string fileExtension;
		System::String^ fileExtensionForms = file_type_comboBox->Text;
		fileExtension = msclr::interop::marshal_as<std::string>(fileExtensionForms);
		std::string fileAndPath = directoryPath + "|" + fileExtension;
		if (send(clientSocket, fileAndPath.c_str(),
			static_cast<int>(fileAndPath.size()) + 1, 0) != SOCKET_ERROR) {
			directory_contents_textbox->Text += Environment::NewLine + "Directory path and file extension sent to the server: " + Environment::NewLine + msclr::interop::marshal_as<System::String^>(fileAndPath) + "\r\n";
			
		}
		else {
			directory_contents_textbox->Text += Environment::NewLine + "Error sending to server. Error code: " + WSAGetLastError() + "\n";
		}
		// Receive the directory contents from the server
		char buffer[65536];
		int bytesRead = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
		if (bytesRead > 0) {
			buffer[bytesRead] = '\0';
			//directory_contents_textbox->Text += Environment::NewLine + "Received directory contents from the server:\n" + Environment::NewLine + msclr::interop::marshal_as<System::String^>(buffer);	
			directory_contents_textbox->AppendText(msclr::interop::marshal_as<System::String^>(buffer));
		}
		else if (bytesRead == 0) {
			directory_contents_textbox->Text += Environment::NewLine + "Server disconnected.";
		}
		else {
			directory_contents_textbox->Text += Environment::NewLine + "Error receiving from server. Error code: " + WSAGetLastError();
		}
		//// Cleanup
		//closesocket(clientSocket);
		//WSACleanup();
	}

private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) 
{   
	file_type_comboBox->Items->Add("all");
	file_type_comboBox->Items->Add(".txt");
	file_type_comboBox->Items->Add(".doc");
	file_type_comboBox->Items->Add(".docx");
	file_type_comboBox->Items->Add(".pdf");
	file_type_comboBox->Items->Add(".ppt");
	file_type_comboBox->Items->Add(".pptx");
	file_type_comboBox->Items->Add(".jpg");
	file_type_comboBox->Items->Add(".png");
	file_type_comboBox->Items->Add(".gif");
	file_type_comboBox->Items->Add(".mp3");
	file_type_comboBox->Items->Add(".mp4");
	file_type_comboBox->Items->Add(".avi");
	file_type_comboBox->Items->Add(".swf");
	file_type_comboBox->Items->Add(".rar");
	file_type_comboBox->Items->Add(".zip");
	file_type_comboBox->Items->Add(".iso");
	file_type_comboBox->Items->Add(".img");
	file_type_comboBox->Items->Add(".exe");
	file_type_comboBox->Items->Add(".dll");
	file_type_comboBox->Items->Add(".bat");
	file_type_comboBox->Items->Add(".cmd");
	file_type_comboBox->Items->Add(".com");
	file_type_comboBox->Items->Add(".msi");
}
};
}
