//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

        int x = -12;
        int y = -8;

        bool startOfTheGame = false;
        int amountOfPointsPlayerLeft = 0;
        int amountOfPointsPlayerRight = 0;
        int numberOfHitsWithTheBall = 0;
        int numberOfRound = 0;

        //char * info = "Welcome to Ping Pong Game.\n\nThe left player controls by pressing the A and Z keys.\nThe right player controls by pressing the up and down buttons.\n\nTo diversify the fun:\nWhen you hit the ball in the center of the paddle, you change its bounce angle and the ball moves faster.\nThe longer you bounce, the ball moves faster.\nYou can freely change the playing field.\n\nHave fun!";


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::p1UpTimer(TObject *Sender)
{
        if (paddle1->Top > 10) paddle1->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::p1DownTimer(TObject *Sender)
{
        if (paddle1->Top + paddle1->Height < back->Height - 10) paddle1->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::p2UpTimer(TObject *Sender)
{
        if (paddle2->Top > 10) paddle2->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::p2DownTimer(TObject *Sender)
{
        if (paddle2->Top + paddle2->Height < back->Height - 10) paddle2->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key == 'A') p1Up->Enabled = true;
        if (Key == 'Z') p1Down->Enabled = true;
        if (Key == VK_UP) p2Up->Enabled = true;
        if (Key == VK_DOWN) p2Down->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key == 'A') p1Up->Enabled = false;
        if (Key == 'Z') p1Down->Enabled = false;
        if (Key == VK_UP) p2Up->Enabled = false;
        if (Key == VK_DOWN) p2Down->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::timerBallTimer(TObject *Sender)
{
        ball->Left += x;
        ball->Top += y;

        //return ball from the top
        if(ball->Top-5 <= back->Top) y = -y;

        //return ball from the bottom
        if(ball->Top+ball->Height+5 >= back->Top+back->Height) y = -y;

        //GAME OVER
        if((ball->Left <= paddle1->Left-15) || (ball->Left+ball->Width >= paddle2->Left+paddle2->Width+15))
        {
                timerBall->Enabled = false;
                ball->Visible = false;
                numberOfRound++;

                // c.d. GAME OVER - final label with information about scored points
                if (ball->Left <= paddle1->Left-15)
                {
                        amountOfPointsPlayerRight++;
                        CurrentRoundResultLabel -> Caption = "Point for the right player >";
                        CurrentRoundResultLabel -> Visible = true;
                } else if (ball->Left+ball->Width >= paddle2->Left+paddle2->Width+15)
                {
                        amountOfPointsPlayerLeft++;
                        CurrentRoundResultLabel -> Caption = "< Point for the left player";
                        CurrentRoundResultLabel -> Visible = true;
                }
                FinalResultOfGameLabel -> Caption = IntToStr(amountOfPointsPlayerLeft) + " : "
                + IntToStr(amountOfPointsPlayerRight);
                FinalResultOfGameLabel -> Visible = true;
                NumberOfHitsWithTheBallLabel -> Caption = "Number of hits with the ball: " +
                IntToStr(numberOfHitsWithTheBall);
                NumberOfHitsWithTheBallLabel -> Visible = true;

                ButtonNextRound -> Visible = true;
                ButtonStartOfTheGame -> Visible = true;
                startOfTheGame = false;
                numberOfHitsWithTheBall = 0;
                timerBall->Interval = 20;

                //Reset of 'x' and 'y' number
                x = -12;
                y = -8;
                //Position of the ball
                ball->Left = 472;
                ball->Top = 384;


                
        } else if (ball->Left <= paddle1->Left+paddle1->Width &&
                ball->Top+ball->Height/2 > paddle1->Top &&
                ball->Top+ball->Height/2 < paddle1->Top+paddle1->Height)
        {
                if (x<0)
                {
                        if (ball->Top+ball->Height/2 == paddle1->Top+paddle1->Height/2)
                        {
                                randomize();
                                int x2 = random(15)+5;
                                x = x2;
                        } else
                        {
                                x = -x;
                        }

                        if (timerBall->Interval>1)
                        {
                                timerBall->Interval-=1;
                        }
                        numberOfHitsWithTheBall++;
                }
        } else if (ball->Left+ball->Width >= paddle2->Left &&
                ball->Top+ball->Height/2 > paddle2->Top &&
                ball->Top+ball->Height/2 < paddle2->Top+paddle2->Height)
        {
                if (x>0)
                {
                        /*if ()
                        {
                            ;
                        } else*/
                        //{
                                x = -x;
                                if (timerBall->Interval>1)
                                {
                                        timerBall->Interval-=1;
                                }
                        //}
                        numberOfHitsWithTheBall++;
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
        Application->MessageBox(
                                "Welcome to Ping Pong Game.\n\n"
                                "The left player controls by pressing the A and Z keys.\n"
                                "The right player controls by pressing the up and down buttons.\n\n"
                                "To diversify the fun:\n"
                                "When you hit the ball in the center of the paddle, you change its "
                                "bounce angle and the ball moves faster.\n"
                                "The longer you bounce, the ball moves faster.\n"
                                "You can freely change the playing field.\n\n"
                                "Have fun!",
                                "PingPongGame", MB_OK);
     /*randomize();
     //x = random(10)+1;
     for (int i = 0; i < 100; i++)
     {
        tab[i] = random(10)+1;
     }*/
     ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonStartOfTheGameClick(TObject *Sender)
{
        if ((startOfTheGame == false) && (numberOfRound == 0))
        {
                ButtonStartOfTheGame->Visible = false;
                WelcomeLabel->Visible = false;
                CurrentRoundResultLabel->Visible = false;
                FinalResultOfGameLabel->Visible = false;
                NumberOfHitsWithTheBallLabel->Visible = false;
                ButtonNextRound->Visible = false;
                ButtonStartOfTheGame->Visible = false;

                amountOfPointsPlayerLeft = 0;
                amountOfPointsPlayerRight = 0;
                numberOfHitsWithTheBall = 0;
                numberOfRound = 0;

                //Position of the paddle1
                paddle1->Left = 64;
                paddle1->Top = 144;
                //Position of the paddle2
                paddle2->Left = 904;
                paddle2->Top = 144;

                startOfTheGame = true;
                timerBall->Enabled = true;
                ball->Visible = true;
        } else if ((startOfTheGame == false) && (numberOfRound != 0))
        {
                if (Application->MessageBox("Are you sure you want to start the game over?",
                "Confirm", MB_YESNO | MB_ICONQUESTION) == IDYES)
                {
                        ButtonStartOfTheGame->Visible = false;
                        WelcomeLabel->Visible = false;
                        CurrentRoundResultLabel->Visible = false;
                        FinalResultOfGameLabel->Visible = false;
                        NumberOfHitsWithTheBallLabel->Visible = false;
                        ButtonNextRound->Visible = false;
                        ButtonStartOfTheGame->Visible = false;

                        amountOfPointsPlayerLeft = 0;
                        amountOfPointsPlayerRight = 0;
                        numberOfHitsWithTheBall = 0;
                        numberOfRound = 0;

                        //Position of the paddle1
                        paddle1->Left = 64;
                        paddle1->Top = 144;
                        //Position of the paddle2
                        paddle2->Left = 904;
                        paddle2->Top = 144;

                        startOfTheGame = true;
                        timerBall->Enabled = true;
                        ball->Visible = true;
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonNextRoundClick(TObject *Sender)
{
        if (startOfTheGame == false)
        {
                ButtonStartOfTheGame->Visible = false;
                WelcomeLabel->Visible = false;
                CurrentRoundResultLabel->Visible = false;
                FinalResultOfGameLabel->Visible = false;
                NumberOfHitsWithTheBallLabel->Visible = false;
                ButtonNextRound->Visible = false;
                ButtonStartOfTheGame->Visible = false;
                
                startOfTheGame = true;
                timerBall->Enabled = true;
                ball->Visible = true;
        }
}
//---------------------------------------------------------------------------

