#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;
//атрибут для функції Main
[STAThreadAttribute] // означає, що функція Main буде запускатись
// в окремому потоці даних
//створення функції Main
int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	TestClient::MyForm form; //створення об'єкту
	Application::Run(% form); //вказуємо % , бо form є обєктом класу
	//посилального типу WinowsForms
}