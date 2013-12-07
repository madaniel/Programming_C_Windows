/***************************************************************/
/*					תוכנית למציאת המספר הסודי					*/ 						
/*--------------------------------------------------------------*/
/*													             */         
/****************************************************************/
/*						:כיתה:            שם:             ציון	*/   
/****************************************************************/
/*																*/					
/*																*/					
/*																*/					
/*				התוכנית תנחש את המספר שבחר המשתמש				*/
/*																*/						 										
/*																*/																									
/*																*/					
/*																*/					
/****************************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>




/*---------  Functions/Functions-Declarations section  --------*/

generate();//הפונקצייה תייצר את כל המספרים החוקיים ותכניס אותם למערך
validation();//פונקציה המקבלת ארבע ספרות ובודקת כפילויות
check();//הפונקציה תקבל 2 מספרים ותחזיר תשובה בול פגיעה
randomize();//פונקציית ניחוש מספרים חוקיים
calculate();//הפונקציה תנחש את המספר הבא על סמך תשובת המשתמש
ask();//פונקציית קליטת המספר
eliminate();//פונקציית סימון מספרים לא פוטנציאלים

//מערך המספרים החוקיים במשחק
int serial [2][5040];



/*---------------------------  Main  --------------------------*/
void main()

/****************************************************************/
/*																*/														
/*																*/				
/****************************************************************/
{
int guess,answer,i;

generate();//הפונקצייה תייצר מספרים חוקיים ותכניס אותם למערך
guess=randomize();
printf("Guess no. 1\n");
printf("%d\nIs this your number?\n",guess);	
answer=ask();//קליטת התשובה מהמשתמש
guess=calculate(answer,guess);

for(i=0;i<20;i++)//לולאת הצגת המספרים
{
	system("cls");
	printf("Guess no. %d\n",i+2);
	if (guess==-1)//בדיקת שגיאה
		{
			system("cls");
			printf("You are mistaking your calculation,\nOr your number is illegal!\n\n");
			break;
		}

	if (guess<1000) 
		printf("0");//שינוי קוסמטי להצגת המספר

	printf("%d\nIs this your number?\n",guess);//הצגת המספר
	answer=ask();
	if (answer==40)//ניחוש נכון
		{
			printf("I knew I can win !!!\n");
			break;
		}
	guess=calculate(answer,guess);	
}

}
/*--------------------  Functions section  --------------------*/

generate()//פונקציית ייצור המספרים החוקיים
{
int number,i=0;
int num1,num2,num3,num4;

for (number=123;number<9877;number++)// לולאת ייצור המספרים
			{
				num4=(number)%10;//פירוק המספר לספרות עשרוניות
				num3=(number/10)%10;
				num2=(number/100)%10;
				num1=(number/1000);
				if (validation(num1,num2,num3,num4)==1)//בדיקת תקינות המספר ע"י שליחה לפונקציה
						{
							serial[0][i]=number;
							i++;
						}
				
			}

}

validation(num1,num2,num3,num4)//הפונקציה מקבלת 4 ספרות ומחזירה ערך אמת במידה ואין כפילויות בין הספרות
{
	
if ((num1==num2)||(num1==num3)||(num1==num4)||(num2==num3)||(num2==num4)||(num3==num4)) 
return 0;
	else return 1;
}

check(number1,number2)//פונקציית בול פגיעה
{
	int i,num[2][4],b=0,p=0;


	for (i=0;i<4;i++)//פירוק המספרים
	{
		num[0][i]=number1%10,num[1][i]=number2%10;
		number1/=10,number2/=10;
	}

	for (i=0;i<4;i++)//לולאת בול
	{
		if (num[0][i]==num[1][i])
			b++;
	}
	
	for (i=1;i<4;i++)//לולאת פגיעה
		if (num[0][0]==num[1][i])	
			p++;
	for (i=2;i>=0;i--)
		if (num[0][3]==num[1][i])
			p++;
	if (num[0][1]==num[1][0]||num[0][1]==num[1][2]||num[0][1]==num[1][3])
		p++;
	if (num[0][2]==num[1][0]||num[0][2]==num[1][1]||num[0][2]==num[1][3])
		p++;
	return (b*10+p);
}



randomize()//הפונקציה תנחש מספר אקראי מתוך המספרים החוקיים
{

int number,num1,num2,num3,num4;

srand( (unsigned)time( NULL ) );

do
	{
		
		number=0;
		while (number<1000||number>9999)//וידוא שהמספר בן 4 ספרות
		{
			number=rand();
		}
		num4=(number)%10;//פירוק המספר לספרות עשרוניות
		num3=(number/10)%10;
		num2=(number/100)%10;
		num1=(number/1000);

	}
while (validation(num1,num2,num3,num4)==0);//וידוא שהמספר בן 4 הספרות הוא גם חוקי

return number;

}

calculate(answer,guess)//הפונקציה תקבל את תשובת המשתמש,תנתח ותחזיר את המספר הבא

{
int i,ok=0;
eliminate(answer,guess);//פוסל מספרים לא פוטנציאלים
for (i=0;!ok;i++)
	{
		if (i==5040)//החזרת שגיאה שנגמרו המספרים
			return -1;
		if (serial[1][i]==1)//מספר שנפסל ע"י הפונקציה או היה בשימוש
			continue;
		ok=1;
	}
i--;
serial[1][i]=1;	//מסמן את המספר שלא יבחר שוב
return serial[0][i];
}

ask()
{
	int answer;
	
do
{
scanf("%d",&answer);
if (answer/10<0||answer/10>4||answer%10<0||answer%10>4||answer>40)
	printf("\nYour answer is illegal,try again.\n");
}
while (answer/10<0||answer/10>4||answer%10<0||answer%10>4||answer>40);
return answer;
}

eliminate(answer,guess)
{
		int i,marked=0,eliminated=0;
		
	
for (i=0;i<5040;i++)
{

	if ((check(serial[0][i],guess)!=answer)&&serial[1][i]==0)
	{
		serial[1][i]=1;
		marked++;
	}

	if (serial[1][i]==1)
		eliminated++;			
}
printf("\n%d numbers scanned, more %d numbers marked,%d numbers remained.\n",i,marked,5040-eliminated);
getch();

}


/****************************    END   *************************/
