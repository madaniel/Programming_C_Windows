/***************************************************************/
/*						פונקציות ומערכים						*/ 						
/*--------------------------------------------------------------*/
/*							                */         
/****************************************************************/
/*						:כיתה:            שם:             ציון	*/   
/****************************************************************/
/*																*/					
/*																*/					
/*																*/					
/*		התכנית תבצע מספר פעולות מתימטיות בעזרת פונקציות			*/
/*																*/						 										
/*																*/																									
/*																*/					
/*																*/					
/****************************************************************/

/*----------------    Pre-Processor section    ----------------*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

/*---------  Functions/Functions-Declarations section  --------*/

power();//פונקציה שתחשב חזקות
CalculatePowerInRange();//פונקציה לחישוב חזקות בטווח המבוקש	
GetUserRequest();//פונקצייה לקליטת הנתונים 
DisplayResults();//פונקציית הדפסה
clear();//פונקצייה לאיפוס המערך לשימוש חוזר


int basis[100],expon[100],result[100];//המערכים
int low,high,pwr;//משתנים גלובלים כי עוברים מפונקציה לפונקציה
/*---------------------------  Main  --------------------------*/
void main()
/****************************************************************/
/*		התכנית הראשית תעבד את הקלט בעזרת קריאה לפונקציות		*/														
/*																*/				
/****************************************************************/
{

do //לולאת הביצוע עד להכנסת 3 מספרים שלילים
	{
		GetUserRequest();
		if (low>0||high>0||pwr>0) //תנאי הפרישה
			{
				CalculatePowerInRange(low,high,pwr);
				DisplayResults();
				clear();
			}
		else break;
		printf("\n\n");
	}
while (low>0||high>0||pwr>0);

}


/*--------------------  Functions section  --------------------*/
power(x,y)//פונקציית חזקה קולטת בסיס וחזקה ומחזירה תוצאה
{
int i,buffer=x;
	for (i=1;i<y;i++)
	{
		buffer*=x;
	}

if (y==0) return 1;
		else return buffer ;


}

CalculatePowerInRange(low,high,pwr)//פונקציה הקולטת תחום של מספרים ומחשבת את חזקתו של כל מספר בתחום
{
int i,num=(high-low);

for (i=0;i<=num;i++,low++)
	{
		result[i]=power(low,pwr);
		basis[i]=low;
		expon[i]=pwr;
	}
}

DisplayResults()
{
	int i=0;
	while (result[i])//הדפסה עד לתא מאופס
		{
			printf("\n%d^%d=%d\t",basis[i],expon[i],result[i]);
			i++;
		}
		
}

GetUserRequest()
	{
		printf("Enter 3 numbers of interval. (low,high,pwr)\n");
		scanf("%d%d%d",&low,&high,&pwr);
	}


		
clear()//איפוס ערכי המערך
{
	int i;
	for (i=0;i<100;i++)
		{	
			basis[i]=0;
			result[i]=0;
			expon[i]=0;
		}

}
/****************************    END   *************************/




