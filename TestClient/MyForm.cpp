#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;
//������� ��� ������� Main
[STAThreadAttribute] // ������, �� ������� Main ���� �����������
// � �������� ������ �����
//��������� ������� Main
int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	TestClient::MyForm form; //��������� ��'����
	Application::Run(% form); //������� % , �� form � ������ �����
	//������������ ���� WinowsForms
}