// ConsoleApplication3.cpp : main project file.
//not: yeni proje oluþturken CLR'nin altýndaki consoleyi seçerek yaptým: burdan öðrendim: http://social.msdn.microsoft.com/Forums/en-US/c7bdc372-ff73-4a04-a620-1bcc473db9bc/namespace-system-not-found
// geliþmiþ bir seri port programý: http://msdn.microsoft.com/en-us/library/system.io.ports.serialport%28VS.90%29.aspx
//basit bir seri port programý: http://msdn.microsoft.com/tr-tr/library/system.io.ports.serialport.datareceived%28v=vs.110%29.aspx



#include "stdafx.h"

#include <iostream>
#include <sstream>
#include <iomanip>

#include <string> //katardan çevirme iþlemi için


#using <System.dll>


using namespace System;
using namespace System::IO::Ports;
using namespace std;
using namespace System::Threading;


void DataReceivedHandler(Object^ sender, SerialDataReceivedEventArgs^ e)
{
	SerialPort^ sp = (SerialPort^)sender;
	//seriportBuffer[seriportSayac] = sp->ReadChar();

	String^ indata = sp->ReadLine(); //gelen veride hem \r hem de \n olmak zorunda

	
	//printf("%c", indata[0]);

	Console::WriteLine("Karakter sayýsý : " + indata->Length.ToString() + " Gelen Veri : " + indata );

}

void seri_port_baglan()
{
	SerialPort^ mySerialPort = gcnew SerialPort("COM1");

	mySerialPort->BaudRate = 9600;
	mySerialPort->Parity = Parity::None;
	mySerialPort->StopBits = StopBits::One;
	mySerialPort->DataBits = 8;
	mySerialPort->Handshake = Handshake::None;

	mySerialPort->DataReceived += gcnew SerialDataReceivedEventHandler(DataReceivedHandler);

	// Set the read/write timeouts
	//mySerialPort->ReadTimeout = 500;
	//mySerialPort->WriteTimeout = 500;

	mySerialPort->Open();

	Console::WriteLine("Baðlantý kuruldu...");
	mySerialPort->Write("Merhaba terminal\r\n");
	
	//mySerialPort->Close();
	
}


//int main()
//int main(array<System::String ^> ^args)
int main(int argc, char** argv)
{
	printf("Merhaba konsol, terminalden +CR ve +LF ile birlikte veri gonderin \r\n");
	seri_port_baglan();
	//Console::ReadKey();
	getchar();
	
	return 0;
}

