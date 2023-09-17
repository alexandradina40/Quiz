//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Objects.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Question_Label;
	TRadioButton *Answer1_Button;
	TRadioButton *Answer2_Button;
	TRadioButton *Answer3_Button;
	TButton *SelectAnswer;
	TLabel *NumberOfPoints;
	TLabel *Points;
	TImage *Image1;
	void __fastcall Answer1_ButtonChange(TObject *Sender);
	void __fastcall Answer2_ButtonChange(TObject *Sender);
	void __fastcall Answer3_ButtonChange(TObject *Sender);
	void __fastcall SelectAnswerClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
