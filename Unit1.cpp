//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop
#include <queue>
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"




class Question
{

public:

	char* Text;
	char* Answer1;
	char* Answer2;
	char* Answer3;
	int CorrectAnswer;
	int Index_for_Picture;

	 Question(){};

	 Question(char* T,char* A1,char* A2,char* A3,int CA,int I)
	 {
		Text=T;
		Answer1=A1;
		Answer2=A2;
		Answer3=A3;
		CorrectAnswer=CA;
		Index_for_Picture=I;
	 }


};

std::queue<Question> LoadQuestions(){
	Question q1=Question("Which color does not appear on the Olympic rings?","Black","Orange","Green",2,1);
	Question q2=Question("What is the chemical formula for Table Salt?","NaCl","NaCl2","Na2Cl",1,2);
	Question q3=Question("What is the longest river in the world?", "Nile","Mississippi","Amazon",1,3);
	Question q4=Question("What happens when you look into Medusa's eyes?", "You get hypnotized","You turn into stone","your head falls off",2,4);
	Question q5=Question("In what country is the Chernobyl nuclear plant located?", "Ukraine","Germany","Poland",1,5);

	std:: vector<Question>vector_for_randomize;
	vector_for_randomize.push_back(q1);
	vector_for_randomize.push_back(q2);
	vector_for_randomize.push_back(q3);
	vector_for_randomize.push_back(q4);
	vector_for_randomize.push_back(q5);

	std::srand(time(0));
	std::random_shuffle(vector_for_randomize.begin(), vector_for_randomize.end());

	std::queue<Question> questions;

	for(int i=0;i<vector_for_randomize.size();i++)
	{
		 questions.push(vector_for_randomize[i]);
	}


	return questions;
}

std::queue<Question> questions;
Question currentQuestion;
int SelectedAnswer,points=0,contor=0;

TForm1 *Form1;
TResourceStream *img;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner): TForm(Owner)
{
   questions=LoadQuestions();
   currentQuestion=questions.front();
   if(currentQuestion.Index_for_Picture==1)
   {
	img =new TResourceStream(0,"First_Question",PChar(RT_RCDATA));
	Image1->Bitmap->LoadFromStream(img);
   }
   if(currentQuestion.Index_for_Picture==2)
   {
	  img =new TResourceStream(0,"Second_Question",PChar(RT_RCDATA));
		Image1->Bitmap->LoadFromStream(img);
   }
   if(currentQuestion.Index_for_Picture==3)
   {
	  img =new TResourceStream(0,"Third_Question",PChar(RT_RCDATA));
		Image1->Bitmap->LoadFromStream(img);
   }
   if(currentQuestion.Index_for_Picture==4)
   {
	  img =new TResourceStream(0,"Forth_Question",PChar(RT_RCDATA));
		Image1->Bitmap->LoadFromStream(img);
   }
   if(currentQuestion.Index_for_Picture==5)
   {
	  img =new TResourceStream(0,"Fiveth_Question",PChar(RT_RCDATA));
		Image1->Bitmap->LoadFromStream(img);
   }

	Question_Label->Text=currentQuestion.Text;
	Answer1_Button->Text=currentQuestion.Answer1;
	Answer2_Button->Text=currentQuestion.Answer2;
	Answer3_Button->Text=currentQuestion.Answer3;
	questions.pop();
	NumberOfPoints->Text=0;

}
//---------------------------------------------------------------------------




void __fastcall TForm1::Answer1_ButtonChange(TObject *Sender)
{
	SelectedAnswer=1;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Answer2_ButtonChange(TObject *Sender)
{
	SelectedAnswer=2;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Answer3_ButtonChange(TObject *Sender)
{
	SelectedAnswer=3;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SelectAnswerClick(TObject *Sender)
{

	if(SelectedAnswer==currentQuestion.CorrectAnswer)
	{
		points++;
		NumberOfPoints->Text=points;

	}



	if(!questions.empty())
	{


		currentQuestion=questions.front();
        Question_Label->Text=currentQuestion.Text;
		Answer1_Button->Text=currentQuestion.Answer1;
		Answer2_Button->Text=currentQuestion.Answer2;
		Answer3_Button->Text=currentQuestion.Answer3;
         if(currentQuestion.Index_for_Picture==1)
	{
		img =new TResourceStream(0,"First_Question",PChar(RT_RCDATA));
		Image1->Bitmap->LoadFromStream(img);
	 }

	   if(currentQuestion.Index_for_Picture==2)
	   {
		  img =new TResourceStream(0,"Second_Question",PChar(RT_RCDATA));
			Image1->Bitmap->LoadFromStream(img);
	   }

	   if(currentQuestion.Index_for_Picture==3)
	   {
		  img =new TResourceStream(0,"Third_Question",PChar(RT_RCDATA));
			Image1->Bitmap->LoadFromStream(img);
	   }

	   if(currentQuestion.Index_for_Picture==4)
	   {
		  img =new TResourceStream(0,"Forth_Question",PChar(RT_RCDATA));
			Image1->Bitmap->LoadFromStream(img);
	   }
	   if(currentQuestion.Index_for_Picture==5)
	   {
		  img =new TResourceStream(0,"Fiveth_Question",PChar(RT_RCDATA));
			Image1->Bitmap->LoadFromStream(img);
	   }
		questions.pop();
		Answer1_Button->IsChecked=false;
		Answer2_Button->IsChecked=false;
		Answer3_Button->IsChecked=false;
	}
	else
	{
		SelectAnswer->Enabled=false;
		SelectAnswer->Text="THE END!";
    }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
	img =new TResourceStream(0,"First_Question",PChar(RT_RCDATA));

}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

