//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *back;
        TImage *ball;
        TImage *paddle1;
        TImage *paddle2;
        TTimer *p1Up;
        TTimer *p1Down;
        TTimer *p2Up;
        TTimer *p2Down;
        TTimer *timerBall;
        TLabel *WelcomeLabel;
        TButton *ButtonStartOfTheGame;
        TLabel *CurrentRoundResultLabel;
        TLabel *FinalResultOfGameLabel;
        TLabel *NumberOfHitsWithTheBallLabel;
        TButton *ButtonNextRound;
        void __fastcall p1UpTimer(TObject *Sender);
        void __fastcall p1DownTimer(TObject *Sender);
        void __fastcall p2UpTimer(TObject *Sender);
        void __fastcall p2DownTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall timerBallTimer(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ButtonStartOfTheGameClick(TObject *Sender);
        void __fastcall ButtonNextRoundClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
