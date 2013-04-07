#pragma once

namespace Envirobot {
#define uint8 unsigned char

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	
			  
	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}










	private: System::Windows::Forms::Button^  BTNstart;
	private: System::Windows::Forms::Button^  BTNsafe;
	private: System::Windows::Forms::Button^  BTNfull;
	private: System::Windows::Forms::TextBox^  TXTbaud;
	private: System::Windows::Forms::Button^  BTNbaud;
	private: System::Windows::Forms::Button^  BTNdemo;
	private: System::Windows::Forms::TextBox^  TXTdemo;
	private: System::Windows::Forms::Button^  BTNdrive;
	private: System::Windows::Forms::TextBox^  TXTdrive1;
	private: System::Windows::Forms::TextBox^  TXTdrive2;
	private: System::Windows::Forms::TextBox^  TXTdrive3;
	private: System::Windows::Forms::TextBox^  TXTdrive4;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  TXTdrivedirect4;

	private: System::Windows::Forms::TextBox^  TXTdrivedirect3;

	private: System::Windows::Forms::TextBox^  TXTdrivedirect2;

	private: System::Windows::Forms::Button^  BTNdrivedirect;
	private: System::Windows::Forms::TextBox^  TXTdrivedirect1;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::TextBox^  TXTleds3;
	private: System::Windows::Forms::TextBox^  TXTleds2;
	private: System::Windows::Forms::Button^  BTNleds;
	private: System::Windows::Forms::TextBox^  TXTleds1;
	private: System::Windows::Forms::Button^  BTNdigitalout;
	private: System::Windows::Forms::TextBox^  TXTdigitalout;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::TextBox^  TXTpwm3;

	private: System::Windows::Forms::TextBox^  TXTpwm2;

	private: System::Windows::Forms::Button^  BTNpwmlowside;
	private: System::Windows::Forms::TextBox^  TXTpwm1;

	private: System::Windows::Forms::Button^  BTNlowsidedrivers;
	private: System::Windows::Forms::TextBox^  TXTlowsidedrivers;
	private: System::Windows::Forms::Button^  BTNsendir;
	private: System::Windows::Forms::TextBox^  TXTsendir;
	private: System::IO::Ports::SerialPort^  serialPort1;
	private: System::Windows::Forms::Button^  BTNstop;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::TrackBar^  BARrayon;
	private: System::Windows::Forms::Label^  LBLrayon;
	private: System::Windows::Forms::TrackBar^  BARvitesse;
	private: System::Windows::Forms::Label^  LBLvitesse;



	private: System::ComponentModel::IContainer^  components;










	protected: 

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
			this->BTNstart = (gcnew System::Windows::Forms::Button());
			this->BTNsafe = (gcnew System::Windows::Forms::Button());
			this->BTNfull = (gcnew System::Windows::Forms::Button());
			this->TXTbaud = (gcnew System::Windows::Forms::TextBox());
			this->BTNbaud = (gcnew System::Windows::Forms::Button());
			this->BTNdemo = (gcnew System::Windows::Forms::Button());
			this->TXTdemo = (gcnew System::Windows::Forms::TextBox());
			this->BTNdrive = (gcnew System::Windows::Forms::Button());
			this->TXTdrive1 = (gcnew System::Windows::Forms::TextBox());
			this->TXTdrive2 = (gcnew System::Windows::Forms::TextBox());
			this->TXTdrive3 = (gcnew System::Windows::Forms::TextBox());
			this->TXTdrive4 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->TXTdrivedirect4 = (gcnew System::Windows::Forms::TextBox());
			this->TXTdrivedirect3 = (gcnew System::Windows::Forms::TextBox());
			this->TXTdrivedirect2 = (gcnew System::Windows::Forms::TextBox());
			this->BTNdrivedirect = (gcnew System::Windows::Forms::Button());
			this->TXTdrivedirect1 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->TXTleds3 = (gcnew System::Windows::Forms::TextBox());
			this->TXTleds2 = (gcnew System::Windows::Forms::TextBox());
			this->BTNleds = (gcnew System::Windows::Forms::Button());
			this->TXTleds1 = (gcnew System::Windows::Forms::TextBox());
			this->BTNdigitalout = (gcnew System::Windows::Forms::Button());
			this->TXTdigitalout = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->TXTpwm3 = (gcnew System::Windows::Forms::TextBox());
			this->TXTpwm2 = (gcnew System::Windows::Forms::TextBox());
			this->BTNpwmlowside = (gcnew System::Windows::Forms::Button());
			this->TXTpwm1 = (gcnew System::Windows::Forms::TextBox());
			this->BTNlowsidedrivers = (gcnew System::Windows::Forms::Button());
			this->TXTlowsidedrivers = (gcnew System::Windows::Forms::TextBox());
			this->BTNsendir = (gcnew System::Windows::Forms::Button());
			this->TXTsendir = (gcnew System::Windows::Forms::TextBox());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->BTNstop = (gcnew System::Windows::Forms::Button());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->BARrayon = (gcnew System::Windows::Forms::TrackBar());
			this->LBLrayon = (gcnew System::Windows::Forms::Label());
			this->BARvitesse = (gcnew System::Windows::Forms::TrackBar());
			this->LBLvitesse = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->BARrayon))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->BARvitesse))->BeginInit();
			this->SuspendLayout();
			// 
			// BTNstart
			// 
			this->BTNstart->Location = System::Drawing::Point(1, 12);
			this->BTNstart->Name = L"BTNstart";
			this->BTNstart->Size = System::Drawing::Size(87, 23);
			this->BTNstart->TabIndex = 3;
			this->BTNstart->Text = L"Start";
			this->BTNstart->UseVisualStyleBackColor = true;
			this->BTNstart->Click += gcnew System::EventHandler(this, &Form1::BTNstart_Click);
			// 
			// BTNsafe
			// 
			this->BTNsafe->Location = System::Drawing::Point(94, 12);
			this->BTNsafe->Name = L"BTNsafe";
			this->BTNsafe->Size = System::Drawing::Size(87, 23);
			this->BTNsafe->TabIndex = 4;
			this->BTNsafe->Text = L"Safe mode";
			this->BTNsafe->UseVisualStyleBackColor = true;
			this->BTNsafe->Click += gcnew System::EventHandler(this, &Form1::BTNsafe_Click);
			// 
			// BTNfull
			// 
			this->BTNfull->Location = System::Drawing::Point(187, 12);
			this->BTNfull->Name = L"BTNfull";
			this->BTNfull->Size = System::Drawing::Size(87, 23);
			this->BTNfull->TabIndex = 5;
			this->BTNfull->Text = L"Full mode";
			this->BTNfull->UseVisualStyleBackColor = true;
			this->BTNfull->Click += gcnew System::EventHandler(this, &Form1::BTNfull_Click);
			// 
			// TXTbaud
			// 
			this->TXTbaud->Location = System::Drawing::Point(94, 43);
			this->TXTbaud->Name = L"TXTbaud";
			this->TXTbaud->Size = System::Drawing::Size(71, 20);
			this->TXTbaud->TabIndex = 6;
			this->TXTbaud->Text = L"0";
			// 
			// BTNbaud
			// 
			this->BTNbaud->Location = System::Drawing::Point(1, 41);
			this->BTNbaud->Name = L"BTNbaud";
			this->BTNbaud->Size = System::Drawing::Size(87, 23);
			this->BTNbaud->TabIndex = 7;
			this->BTNbaud->Text = L"Baud";
			this->BTNbaud->UseVisualStyleBackColor = true;
			this->BTNbaud->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// BTNdemo
			// 
			this->BTNdemo->Location = System::Drawing::Point(1, 70);
			this->BTNdemo->Name = L"BTNdemo";
			this->BTNdemo->Size = System::Drawing::Size(87, 23);
			this->BTNdemo->TabIndex = 9;
			this->BTNdemo->Text = L"Demo";
			this->BTNdemo->UseVisualStyleBackColor = true;
			this->BTNdemo->Click += gcnew System::EventHandler(this, &Form1::BTNdemo_Click);
			// 
			// TXTdemo
			// 
			this->TXTdemo->Location = System::Drawing::Point(94, 72);
			this->TXTdemo->Name = L"TXTdemo";
			this->TXTdemo->Size = System::Drawing::Size(71, 20);
			this->TXTdemo->TabIndex = 8;
			this->TXTdemo->Text = L"0";
			// 
			// BTNdrive
			// 
			this->BTNdrive->Location = System::Drawing::Point(1, 112);
			this->BTNdrive->Name = L"BTNdrive";
			this->BTNdrive->Size = System::Drawing::Size(87, 23);
			this->BTNdrive->TabIndex = 11;
			this->BTNdrive->Text = L"Drive";
			this->BTNdrive->UseVisualStyleBackColor = true;
			this->BTNdrive->Click += gcnew System::EventHandler(this, &Form1::BTNdrive_Click);
			// 
			// TXTdrive1
			// 
			this->TXTdrive1->Location = System::Drawing::Point(94, 114);
			this->TXTdrive1->Name = L"TXTdrive1";
			this->TXTdrive1->Size = System::Drawing::Size(71, 20);
			this->TXTdrive1->TabIndex = 10;
			this->TXTdrive1->Text = L"0";
			// 
			// TXTdrive2
			// 
			this->TXTdrive2->Location = System::Drawing::Point(171, 115);
			this->TXTdrive2->Name = L"TXTdrive2";
			this->TXTdrive2->Size = System::Drawing::Size(71, 20);
			this->TXTdrive2->TabIndex = 12;
			this->TXTdrive2->Text = L"0";
			// 
			// TXTdrive3
			// 
			this->TXTdrive3->Location = System::Drawing::Point(248, 115);
			this->TXTdrive3->Name = L"TXTdrive3";
			this->TXTdrive3->Size = System::Drawing::Size(71, 20);
			this->TXTdrive3->TabIndex = 13;
			this->TXTdrive3->Text = L"0";
			// 
			// TXTdrive4
			// 
			this->TXTdrive4->Location = System::Drawing::Point(325, 115);
			this->TXTdrive4->Name = L"TXTdrive4";
			this->TXTdrive4->Size = System::Drawing::Size(71, 20);
			this->TXTdrive4->TabIndex = 14;
			this->TXTdrive4->Text = L"0";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(101, 98);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 13);
			this->label1->TabIndex = 15;
			this->label1->Text = L"velocity_h";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(181, 98);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 13);
			this->label2->TabIndex = 16;
			this->label2->Text = L"velocity_l";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(266, 99);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(47, 13);
			this->label3->TabIndex = 17;
			this->label3->Text = L"radius_h";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(344, 98);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(43, 13);
			this->label4->TabIndex = 18;
			this->label4->Text = L"radius_l";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(335, 139);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(54, 13);
			this->label5->TabIndex = 27;
			this->label5->Text = L"lVelocity_l";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(255, 139);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(58, 13);
			this->label6->TabIndex = 26;
			this->label6->Text = L"lVelocity_h";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(181, 138);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(55, 13);
			this->label7->TabIndex = 25;
			this->label7->Text = L"rVelocity_l";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(101, 138);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(59, 13);
			this->label8->TabIndex = 24;
			this->label8->Text = L"rVelocity_h";
			// 
			// TXTdrivedirect4
			// 
			this->TXTdrivedirect4->Location = System::Drawing::Point(325, 155);
			this->TXTdrivedirect4->Name = L"TXTdrivedirect4";
			this->TXTdrivedirect4->Size = System::Drawing::Size(71, 20);
			this->TXTdrivedirect4->TabIndex = 23;
			this->TXTdrivedirect4->Text = L"0";
			// 
			// TXTdrivedirect3
			// 
			this->TXTdrivedirect3->Location = System::Drawing::Point(248, 155);
			this->TXTdrivedirect3->Name = L"TXTdrivedirect3";
			this->TXTdrivedirect3->Size = System::Drawing::Size(71, 20);
			this->TXTdrivedirect3->TabIndex = 22;
			this->TXTdrivedirect3->Text = L"0";
			// 
			// TXTdrivedirect2
			// 
			this->TXTdrivedirect2->Location = System::Drawing::Point(171, 155);
			this->TXTdrivedirect2->Name = L"TXTdrivedirect2";
			this->TXTdrivedirect2->Size = System::Drawing::Size(71, 20);
			this->TXTdrivedirect2->TabIndex = 21;
			this->TXTdrivedirect2->Text = L"0";
			// 
			// BTNdrivedirect
			// 
			this->BTNdrivedirect->Location = System::Drawing::Point(1, 152);
			this->BTNdrivedirect->Name = L"BTNdrivedirect";
			this->BTNdrivedirect->Size = System::Drawing::Size(87, 23);
			this->BTNdrivedirect->TabIndex = 20;
			this->BTNdrivedirect->Text = L"DriveDirect";
			this->BTNdrivedirect->UseVisualStyleBackColor = true;
			this->BTNdrivedirect->Click += gcnew System::EventHandler(this, &Form1::BTNdrivedirect_Click);
			// 
			// TXTdrivedirect1
			// 
			this->TXTdrivedirect1->Location = System::Drawing::Point(94, 154);
			this->TXTdrivedirect1->Name = L"TXTdrivedirect1";
			this->TXTdrivedirect1->Size = System::Drawing::Size(71, 20);
			this->TXTdrivedirect1->TabIndex = 19;
			this->TXTdrivedirect1->Text = L"0";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(255, 179);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(48, 13);
			this->label10->TabIndex = 35;
			this->label10->Text = L"powerInt";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(181, 178);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(51, 13);
			this->label11->TabIndex = 34;
			this->label11->Text = L"powerCol";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(101, 178);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(45, 13);
			this->label12->TabIndex = 33;
			this->label12->Text = L"LEDBits";
			// 
			// TXTleds3
			// 
			this->TXTleds3->Location = System::Drawing::Point(248, 195);
			this->TXTleds3->Name = L"TXTleds3";
			this->TXTleds3->Size = System::Drawing::Size(71, 20);
			this->TXTleds3->TabIndex = 31;
			this->TXTleds3->Text = L"0";
			// 
			// TXTleds2
			// 
			this->TXTleds2->Location = System::Drawing::Point(171, 195);
			this->TXTleds2->Name = L"TXTleds2";
			this->TXTleds2->Size = System::Drawing::Size(71, 20);
			this->TXTleds2->TabIndex = 30;
			this->TXTleds2->Text = L"0";
			// 
			// BTNleds
			// 
			this->BTNleds->Location = System::Drawing::Point(1, 192);
			this->BTNleds->Name = L"BTNleds";
			this->BTNleds->Size = System::Drawing::Size(87, 23);
			this->BTNleds->TabIndex = 29;
			this->BTNleds->Text = L"LEDs";
			this->BTNleds->UseVisualStyleBackColor = true;
			this->BTNleds->Click += gcnew System::EventHandler(this, &Form1::BTNleds_Click);
			// 
			// TXTleds1
			// 
			this->TXTleds1->Location = System::Drawing::Point(94, 194);
			this->TXTleds1->Name = L"TXTleds1";
			this->TXTleds1->Size = System::Drawing::Size(71, 20);
			this->TXTleds1->TabIndex = 28;
			this->TXTleds1->Text = L"0";
			// 
			// BTNdigitalout
			// 
			this->BTNdigitalout->Location = System::Drawing::Point(1, 276);
			this->BTNdigitalout->Name = L"BTNdigitalout";
			this->BTNdigitalout->Size = System::Drawing::Size(87, 23);
			this->BTNdigitalout->TabIndex = 37;
			this->BTNdigitalout->Text = L"DigitalOut";
			this->BTNdigitalout->UseVisualStyleBackColor = true;
			this->BTNdigitalout->Click += gcnew System::EventHandler(this, &Form1::BTNdigitalout_Click);
			// 
			// TXTdigitalout
			// 
			this->TXTdigitalout->Location = System::Drawing::Point(94, 278);
			this->TXTdigitalout->Name = L"TXTdigitalout";
			this->TXTdigitalout->Size = System::Drawing::Size(71, 20);
			this->TXTdigitalout->TabIndex = 36;
			this->TXTdigitalout->Text = L"0";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(255, 223);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(56, 13);
			this->label9->TabIndex = 44;
			this->label9->Text = L"LSD0Duty";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(181, 222);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(56, 13);
			this->label13->TabIndex = 43;
			this->label13->Text = L"LSD1Duty";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(101, 222);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(56, 13);
			this->label14->TabIndex = 42;
			this->label14->Text = L"LSD2Duty";
			// 
			// TXTpwm3
			// 
			this->TXTpwm3->Location = System::Drawing::Point(248, 239);
			this->TXTpwm3->Name = L"TXTpwm3";
			this->TXTpwm3->Size = System::Drawing::Size(71, 20);
			this->TXTpwm3->TabIndex = 41;
			this->TXTpwm3->Text = L"0";
			// 
			// TXTpwm2
			// 
			this->TXTpwm2->Location = System::Drawing::Point(171, 239);
			this->TXTpwm2->Name = L"TXTpwm2";
			this->TXTpwm2->Size = System::Drawing::Size(71, 20);
			this->TXTpwm2->TabIndex = 40;
			this->TXTpwm2->Text = L"0";
			// 
			// BTNpwmlowside
			// 
			this->BTNpwmlowside->Location = System::Drawing::Point(1, 236);
			this->BTNpwmlowside->Name = L"BTNpwmlowside";
			this->BTNpwmlowside->Size = System::Drawing::Size(87, 23);
			this->BTNpwmlowside->TabIndex = 39;
			this->BTNpwmlowside->Text = L"PWMLowSide";
			this->BTNpwmlowside->UseVisualStyleBackColor = true;
			this->BTNpwmlowside->Click += gcnew System::EventHandler(this, &Form1::BTNpwmlowside_Click);
			// 
			// TXTpwm1
			// 
			this->TXTpwm1->Location = System::Drawing::Point(94, 238);
			this->TXTpwm1->Name = L"TXTpwm1";
			this->TXTpwm1->Size = System::Drawing::Size(71, 20);
			this->TXTpwm1->TabIndex = 38;
			this->TXTpwm1->Text = L"0";
			// 
			// BTNlowsidedrivers
			// 
			this->BTNlowsidedrivers->Location = System::Drawing::Point(1, 305);
			this->BTNlowsidedrivers->Name = L"BTNlowsidedrivers";
			this->BTNlowsidedrivers->Size = System::Drawing::Size(87, 23);
			this->BTNlowsidedrivers->TabIndex = 46;
			this->BTNlowsidedrivers->Text = L"LowSideDrivers";
			this->BTNlowsidedrivers->UseVisualStyleBackColor = true;
			this->BTNlowsidedrivers->Click += gcnew System::EventHandler(this, &Form1::BTNlowsidedrivers_Click);
			// 
			// TXTlowsidedrivers
			// 
			this->TXTlowsidedrivers->Location = System::Drawing::Point(94, 305);
			this->TXTlowsidedrivers->Name = L"TXTlowsidedrivers";
			this->TXTlowsidedrivers->Size = System::Drawing::Size(71, 20);
			this->TXTlowsidedrivers->TabIndex = 45;
			this->TXTlowsidedrivers->Text = L"0";
			// 
			// BTNsendir
			// 
			this->BTNsendir->Location = System::Drawing::Point(1, 334);
			this->BTNsendir->Name = L"BTNsendir";
			this->BTNsendir->Size = System::Drawing::Size(87, 23);
			this->BTNsendir->TabIndex = 48;
			this->BTNsendir->Text = L"SendIR";
			this->BTNsendir->UseVisualStyleBackColor = true;
			this->BTNsendir->Click += gcnew System::EventHandler(this, &Form1::BTNsendir_Click);
			// 
			// TXTsendir
			// 
			this->TXTsendir->Location = System::Drawing::Point(94, 334);
			this->TXTsendir->Name = L"TXTsendir";
			this->TXTsendir->Size = System::Drawing::Size(71, 20);
			this->TXTsendir->TabIndex = 47;
			this->TXTsendir->Text = L"0";
			// 
			// BTNstop
			// 
			this->BTNstop->Location = System::Drawing::Point(439, 12);
			this->BTNstop->Name = L"BTNstop";
			this->BTNstop->Size = System::Drawing::Size(75, 23);
			this->BTNstop->TabIndex = 49;
			this->BTNstop->Text = L"STOP !";
			this->BTNstop->UseVisualStyleBackColor = true;
			this->BTNstop->Click += gcnew System::EventHandler(this, &Form1::BTNstop_Click);
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(418, 38);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(41, 13);
			this->label15->TabIndex = 50;
			this->label15->Text = L"Vitesse";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(492, 38);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(98, 13);
			this->label16->TabIndex = 51;
			this->label16->Text = L"Rayon de courbure";
			// 
			// BARrayon
			// 
			this->BARrayon->LargeChange = 50;
			this->BARrayon->Location = System::Drawing::Point(526, 54);
			this->BARrayon->Maximum = 2000;
			this->BARrayon->Minimum = -2000;
			this->BARrayon->Name = L"BARrayon";
			this->BARrayon->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->BARrayon->Size = System::Drawing::Size(42, 204);
			this->BARrayon->SmallChange = 5;
			this->BARrayon->TabIndex = 52;
			this->BARrayon->TickFrequency = 150;
			this->BARrayon->ValueChanged += gcnew System::EventHandler(this, &Form1::BARrayon_ValueChanged);
			this->BARrayon->Scroll += gcnew System::EventHandler(this, &Form1::BARrayon_Scroll);
			// 
			// LBLrayon
			// 
			this->LBLrayon->AutoSize = true;
			this->LBLrayon->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->LBLrayon->Location = System::Drawing::Point(565, 152);
			this->LBLrayon->Name = L"LBLrayon";
			this->LBLrayon->Size = System::Drawing::Size(34, 15);
			this->LBLrayon->TabIndex = 53;
			this->LBLrayon->Text = L"0 mm";
			// 
			// BARvitesse
			// 
			this->BARvitesse->LargeChange = 50;
			this->BARvitesse->Location = System::Drawing::Point(421, 54);
			this->BARvitesse->Maximum = 500;
			this->BARvitesse->Minimum = -500;
			this->BARvitesse->Name = L"BARvitesse";
			this->BARvitesse->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->BARvitesse->Size = System::Drawing::Size(42, 204);
			this->BARvitesse->SmallChange = 5;
			this->BARvitesse->TabIndex = 54;
			this->BARvitesse->TickFrequency = 50;
			this->BARvitesse->ValueChanged += gcnew System::EventHandler(this, &Form1::BARvitesse_ValueChanged);
			this->BARvitesse->Scroll += gcnew System::EventHandler(this, &Form1::BARvitesse_Scroll);
			// 
			// LBLvitesse
			// 
			this->LBLvitesse->AutoSize = true;
			this->LBLvitesse->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->LBLvitesse->Location = System::Drawing::Point(458, 152);
			this->LBLvitesse->Name = L"LBLvitesse";
			this->LBLvitesse->Size = System::Drawing::Size(44, 15);
			this->LBLvitesse->TabIndex = 55;
			this->LBLvitesse->Text = L"0 mm/s";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(630, 407);
			this->Controls->Add(this->LBLvitesse);
			this->Controls->Add(this->BARvitesse);
			this->Controls->Add(this->LBLrayon);
			this->Controls->Add(this->BARrayon);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->BTNstop);
			this->Controls->Add(this->BTNsendir);
			this->Controls->Add(this->TXTsendir);
			this->Controls->Add(this->BTNlowsidedrivers);
			this->Controls->Add(this->TXTlowsidedrivers);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->TXTpwm3);
			this->Controls->Add(this->TXTpwm2);
			this->Controls->Add(this->BTNpwmlowside);
			this->Controls->Add(this->TXTpwm1);
			this->Controls->Add(this->BTNdigitalout);
			this->Controls->Add(this->TXTdigitalout);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->TXTleds3);
			this->Controls->Add(this->TXTleds2);
			this->Controls->Add(this->BTNleds);
			this->Controls->Add(this->TXTleds1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->TXTdrivedirect4);
			this->Controls->Add(this->TXTdrivedirect3);
			this->Controls->Add(this->TXTdrivedirect2);
			this->Controls->Add(this->BTNdrivedirect);
			this->Controls->Add(this->TXTdrivedirect1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->TXTdrive4);
			this->Controls->Add(this->TXTdrive3);
			this->Controls->Add(this->TXTdrive2);
			this->Controls->Add(this->BTNdrive);
			this->Controls->Add(this->TXTdrive1);
			this->Controls->Add(this->BTNdemo);
			this->Controls->Add(this->TXTdemo);
			this->Controls->Add(this->BTNbaud);
			this->Controls->Add(this->TXTbaud);
			this->Controls->Add(this->BTNfull);
			this->Controls->Add(this->BTNsafe);
			this->Controls->Add(this->BTNstart);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form1::Form1_FormClosed);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->BARrayon))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->BARvitesse))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void BTNstart_Click(System::Object^  sender, System::EventArgs^  e) {
			 iC_Start();
		 }
private: System::Void BTNsafe_Click(System::Object^  sender, System::EventArgs^  e) {
			 iC_Safe();
		 }
private: System::Void BTNfull_Click(System::Object^  sender, System::EventArgs^  e) {
			 iC_Full();
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 int value;
			 unsigned char cvalue;
			 try{
				 value=int::Parse(TXTbaud->Text);
			 }
			 catch(...)
			 {
				 return;
			 }
			 cvalue = (unsigned char)(value);
			 iC_Baud(cvalue);
		 }
private: System::Void BTNdemo_Click(System::Object^  sender, System::EventArgs^  e) {
			 int value;
			 unsigned char cvalue;
			 try{
				 value=int::Parse(TXTdemo->Text);
			 }
			 catch(...)
			 {
				 return;
			 }
			 cvalue = (unsigned char)(value);
			 iC_Demo(cvalue);
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		 initSerial("com1", 57600, 8, 1,0);
		 }


private: System::Void BTNdrive_Click(System::Object^  sender, System::EventArgs^  e) {
			 int value1,value2,value3,value4;
			 unsigned char cvalue1,cvalue2,cvalue3,cvalue4;
			 try{
				 value1=int::Parse(TXTdrive1->Text);
				 value2=int::Parse(TXTdrive2->Text);
				 value3=int::Parse(TXTdrive3->Text);
				 value4=int::Parse(TXTdrive4->Text);
			 }
			 catch(...)
			 {
				 return;
			 }
			 cvalue1 = (unsigned char)(value1);
			 cvalue2 = (unsigned char)(value2);
			 cvalue3 = (unsigned char)(value3);
			 cvalue4 = (unsigned char)(value4);
			 iC_Drive(cvalue1,cvalue2,cvalue3,value4);
		 }
private: System::Void BTNdrivedirect_Click(System::Object^  sender, System::EventArgs^  e) {
			 int value1,value2,value3,value4;
			 unsigned char cvalue1,cvalue2,cvalue3,cvalue4;
			 try{
				 value1=int::Parse(TXTdrivedirect1->Text);
				 value2=int::Parse(TXTdrivedirect2->Text);
				 value3=int::Parse(TXTdrivedirect3->Text);
				 value4=int::Parse(TXTdrivedirect4->Text);
			 }
			 catch(...)
			 {
				 return;
			 }
			 cvalue1 = (unsigned char)(value1);
			 cvalue2 = (unsigned char)(value2);
			 cvalue3 = (unsigned char)(value3);
			 cvalue4 = (unsigned char)(value4);
			 iC_DriveDirect(cvalue1,cvalue2,cvalue3,value4);
		 }
private: System::Void BTNleds_Click(System::Object^  sender, System::EventArgs^  e) {
			 int value1,value2,value3;
			 unsigned char cvalue1,cvalue2,cvalue3;
			 try{
				 value1=int::Parse(TXTleds1->Text);
				 value2=int::Parse(TXTleds2->Text);
				 value3=int::Parse(TXTleds3->Text);
			 }
			 catch(...)
			 {
				 return;
			 }
			 cvalue1 = (unsigned char)(value1);
			 cvalue2 = (unsigned char)(value2);
			 cvalue3 = (unsigned char)(value3);
			 iC_LEDs(cvalue1,cvalue2,cvalue3);
		 
		 }
private: System::Void BTNpwmlowside_Click(System::Object^  sender, System::EventArgs^  e) {
			 int value1,value2,value3;
			 unsigned char cvalue1,cvalue2,cvalue3;
			 try{
				 value1=int::Parse(TXTpwm1->Text);
				 value2=int::Parse(TXTpwm2->Text);
				 value3=int::Parse(TXTpwm3->Text);
			 }
			 catch(...)
			 {
				 return;
			 }
			 cvalue1 = (unsigned char)(value1);
			 cvalue2 = (unsigned char)(value2);
			 cvalue3 = (unsigned char)(value3);
			 iC_PWMLowSide(cvalue1,cvalue2,cvalue3);
		 }
private: System::Void BTNdigitalout_Click(System::Object^  sender, System::EventArgs^  e) {
			 int value;
			 unsigned char cvalue;
			 try{
				 value=int::Parse(TXTdigitalout->Text);
			 }
			 catch(...)
			 {
				 return;
			 }
			 cvalue = (unsigned char)(value);
			 iC_DigitalOut(cvalue);
		 }
private: System::Void BTNlowsidedrivers_Click(System::Object^  sender, System::EventArgs^  e) {
			 int value;
			 unsigned char cvalue;
			 try{
				 value=int::Parse(TXTlowsidedrivers->Text);
			 }
			 catch(...)
			 {
				 return;
			 }
			 cvalue = (unsigned char)(value);
			 iC_LowSideDrivers(cvalue);
		 }
private: System::Void BTNsendir_Click(System::Object^  sender, System::EventArgs^  e) {
			 int value;
			 unsigned char cvalue;
			 try{
				 value=int::Parse(TXTsendir->Text);
			 }
			 catch(...)
			 {
				 return;
			 }
			 cvalue = (unsigned char)(value);
			 iC_SendIR(cvalue);
		 }

private: int initSerial(char* device, long baudrate, int nData, int nStop, int parity)
		 {
			 
			 //serialPort1->PortName = serialPort1->GetPortNames()[0]; //  System::IO::Ports::SerialPort::PortName
			 serialPort1->PortName = "COM3"; //  System::IO::Ports::SerialPort::PortName
			 serialPort1->BaudRate = 57600;
			 serialPort1->Parity = System::IO::Ports::Parity::None;
			 serialPort1->DataBits = 8;
			 serialPort1->StopBits = System::IO::Ports::StopBits::One;
			 serialPort1->Open();
			 return 0;
		 }

private: System::Void sendSerial(int junk, unsigned char data)
		 {
			  cli::array<unsigned char> ^ Trame=gcnew array<unsigned char>(1);
			  Trame[0]=data;
			 serialPort1->Write(Trame,0,1);
		 }

private: System::Void flushRecieveBuffer(int junk)
		{
			serialPort1->DiscardInBuffer();
		}

private: int receiveSerial(int junk, int bytesToRead=1)
		{
			cli::array<unsigned char> ^ Trame=gcnew array<unsigned char>(1);
			while(serialPort1->BytesToRead!=bytesToRead);
			serialPort1->Read(Trame,0,bytesToRead);
			if(bytesToRead==2)
				return ((Trame[0]<<8)+Trame[1]);
			else
				return Trame[0];
		}

private:
int iCreateCom;

/****************************************************
** Copier ici le corps de iCreateLib.c
*****************************************************/


void initICreateCom(char* device)
{
  iCreateCom = initSerial(device, 57600, 8, 1, 0);
}

//primitive d'initialisation de la comunication avec l'iCreate
void iC_Start(void)
{
  sendSerial(iCreateCom,128);
}

void iC_Baud(uint8 baudCode)
{
  /*rajouter un test de validité de la valeur*/
  sendSerial(iCreateCom,129);
  sendSerial(iCreateCom,baudCode);
}


void iC_Safe(void)
{
  sendSerial(iCreateCom,131);
  flushRecieveBuffer(iCreateCom);
}

void iC_Full(void)
{
  sendSerial(iCreateCom,132);
  flushRecieveBuffer(iCreateCom);
}

void iC_Demo(uint8 demoID)
{
  sendSerial(iCreateCom,136);
  sendSerial(iCreateCom,demoID);
}

void iC_Drive(uint8 velocity_h, uint8 velocity_l, uint8 radius_h, uint8 radius_l)
{
  sendSerial(iCreateCom,137);
  sendSerial(iCreateCom,velocity_h);
  sendSerial(iCreateCom,velocity_l);
  sendSerial(iCreateCom,radius_h);
  sendSerial(iCreateCom,radius_l);
}

void iC_DriveDirect(uint8 rVelocity_h, uint8 rVelocity_l, uint8 lVelocity_h, uint8 lVelocity_l)
{
  sendSerial(iCreateCom,145);
  sendSerial(iCreateCom,rVelocity_h);
  sendSerial(iCreateCom,rVelocity_l);
  sendSerial(iCreateCom,lVelocity_h);
	sendSerial(iCreateCom,lVelocity_l);
}

void iC_LEDs(uint8 LEDBits, uint8 powerCol, uint8 powerInt)
{
  sendSerial(iCreateCom,139);
  sendSerial(iCreateCom,LEDBits);
  sendSerial(iCreateCom,powerCol);
  sendSerial(iCreateCom,powerInt);
}

void iC_DigitalOut(uint8 outBits)
{
  sendSerial(iCreateCom,147);
  sendSerial(iCreateCom,outBits);
}

void iC_PWMLowSide(uint8 LSD2Duty, uint8 LSD1Duty, uint8 LSD0Duty)
{
  sendSerial(iCreateCom,144);
  sendSerial(iCreateCom,LSD2Duty);
  sendSerial(iCreateCom,LSD1Duty);
  sendSerial(iCreateCom,LSD0Duty);
}

void iC_LowSideDrivers(uint8 driverBits)
{
  sendSerial(iCreateCom,138);
  sendSerial(iCreateCom,driverBits);
}

void iC_SendIR(uint8 byteValue)
{
  sendSerial(iCreateCom,151);
  sendSerial(iCreateCom,byteValue);
}

void iC_Sensor(uint8 sensorId)
{
  sendSerial(iCreateCom,142);
  sendSerial(iCreateCom,sensorId);
}


//---------------------------------------

/*
//accesseur du capteur Bumper
uint8 iC_getBumper()
{
  iC_Sensor(7);
  return receiveSerial(iCreateCom);
}

//accesseur du capteur Wall
uint8 iC_getWall()
{
  iC_Sensor(8);
  return receiveSerial(iCreateCom);
}*/

uint8 iC_getBumpsAndWDrops()
{
  iC_Sensor(7);
  return receiveSerial(iCreateCom);
}

uint8 iC_getWall()
{
  iC_Sensor(8);
  return receiveSerial(iCreateCom);
}

uint8 iC_getCliffL()
{
  iC_Sensor(9);
  return receiveSerial(iCreateCom);
}

uint8 iC_getCliffFL()
{
  iC_Sensor(10);
  return receiveSerial(iCreateCom);
}

uint8 iC_getCliffFR()
{
  iC_Sensor(11);
  return receiveSerial(iCreateCom);
}

uint8 iC_getCliffR()
{
  iC_Sensor(12);
  return receiveSerial(iCreateCom);
}

uint8 iC_getVirtualWall()
{
  iC_Sensor(13);
  return receiveSerial(iCreateCom);
}

uint8 iC_getOvercurrents()
{
  iC_Sensor(14);
  return receiveSerial(iCreateCom);
}

uint8 iC_getIRByte()
{
  iC_Sensor(17);
  return receiveSerial(iCreateCom);
}

uint8 iC_getButtons()
{
  iC_Sensor(18);
  return receiveSerial(iCreateCom);
}

uint8 iC_getDistance()
{
  iC_Sensor(19);
  return receiveSerial(iCreateCom);
}

uint8 iC_getAngle()
{
  iC_Sensor(20);
  return receiveSerial(iCreateCom);
}

uint8 iC_getChargeState()
{
  iC_Sensor(21);
  return receiveSerial(iCreateCom);
}

uint8 iC_getVoltage()
{
  iC_Sensor(22);
  return receiveSerial(iCreateCom);
}

uint8 iC_getCurrent()
{
  iC_Sensor(23);
  return receiveSerial(iCreateCom);
}

uint8 iC_getBattTemp()
{
  iC_Sensor(24);
  return receiveSerial(iCreateCom);
}

uint8 iC_getBattCharge()
{
  iC_Sensor(25);
  return receiveSerial(iCreateCom);
}

uint8 iC_getBattCap()
{
  iC_Sensor(26);
  return receiveSerial(iCreateCom);
}

uint8 iC_getWallSig()
{
  iC_Sensor(27);
  return receiveSerial(iCreateCom);
}

uint8 iC_getCliffLSig()
{
  iC_Sensor(28);
  return receiveSerial(iCreateCom);
}

uint8 iC_getCliffFLSig()
{
  iC_Sensor(29);
  return receiveSerial(iCreateCom);
}

uint8 iC_getCliffFRSig()
{
  iC_Sensor(30);
  return receiveSerial(iCreateCom);
}

uint8 iC_getCliffRSig()
{
  iC_Sensor(31);
  return receiveSerial(iCreateCom);
}

uint8 iC_getDigitalIn()
{
  iC_Sensor(32);
  return receiveSerial(iCreateCom);
}

uint8 iC_getAnalogIn()
{
  iC_Sensor(33);
  return receiveSerial(iCreateCom);
}

uint8 iC_getChargeSrcAvailable()
{
  iC_Sensor(34);
  return receiveSerial(iCreateCom);
}

uint8 iC_getOIMode()
{
  iC_Sensor(35);
  return receiveSerial(iCreateCom);
}

uint8 iC_getSongNumber()
{
  iC_Sensor(36);
  return receiveSerial(iCreateCom);
}

uint8 iC_getSongPlaying()
{
  iC_Sensor(37);
  return receiveSerial(iCreateCom);
}

uint8 iC_getNStreamPackets()
{
  iC_Sensor(38);
  return receiveSerial(iCreateCom);
}

uint8 iC_getVelocity()
{
  iC_Sensor(39);
  return receiveSerial(iCreateCom);
}

uint8 iC_getRadius()
{
  iC_Sensor(40);
  return receiveSerial(iCreateCom);
}

uint8 iC_getRVelocity()
{
  iC_Sensor(41);
  return receiveSerial(iCreateCom);
}

uint8 iC_getLVelocity()
{
  iC_Sensor(42);
  return receiveSerial(iCreateCom);
}



/********************************************************
********************************************************/






/********************************************************
** Fonctions de plus haut niveau
********************************************************/


void Tourne(int Vitesse,int Rayon,bool Sens);
void Stop(void);
void Pivot(int Vitesse);
int CapteurSol(uint8 Nro);
int CapteurMur(void);
uint8 CapteurBouclier(void);
uint8 CapteurInfrarouge(void);
void Buzzer(uint8 NbrBuzz,uint8 Duree);

/********************************************************/

private: System::Void Form1_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
			 serialPort1->Close();
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 uint8 a = iC_getDistance();
		 }
private: System::Void BARrayon_Scroll(System::Object^  sender, System::EventArgs^  e) {
			 LBLrayon->Text=BARrayon->Value.ToString() + " mm";
		 }
private: System::Void BARvitesse_Scroll(System::Object^  sender, System::EventArgs^  e) {
			 LBLvitesse->Text=BARvitesse->Value.ToString() + " mm/s";
		 }
private: System::Void BARvitesse_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			RefreshDrive();
		 }

private: System::Void RefreshDrive() {
			 unsigned char lByteVitesse;
			 unsigned char hByteVitesse;
			 unsigned char lByteRayon;
			 unsigned char hByteRayon;
			 int vitesse;
			 int rayon;
			 vitesse = (BARvitesse->Value);
			 rayon = (BARrayon->Value);
			 lByteVitesse = vitesse & 0x00FF;
			 hByteVitesse = (vitesse & 0xFF00)>>8;
			 lByteRayon = rayon & 0x00FF;
			 hByteRayon = (rayon & 0xFF00)>>8;
			 iC_Drive(hByteVitesse, lByteVitesse, hByteRayon, lByteRayon);
		 }

private: System::Void BARrayon_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			RefreshDrive();
		 }
private: System::Void BTNstop_Click(System::Object^  sender, System::EventArgs^  e) {
			 iC_DriveDirect(0,0,0,0);
		 }
};

}

