/***************************************************************/
/*							תוכנית לולאות						*/ 						
/*--------------------------------------------------------------*/
/****************************************************************/
/*						:כיתה:            שם:             ציון	*/   
/****************************************************************/
/*																*/					
/*																*/					
/*																*/					
/*					התוכנית מבצעת 3 פעולות						*/
/*		מציירת מלבן ע"פ נתונים, מזהה סוגי משולשים וסופרת תווים	*/						 										
/*																*/																									
/*																*/					
/*																*/					
/****************************************************************/

/*----------------    Pre-Processor section    ----------------*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>

/*---------  Functions/Functions-Declarations section  --------*/


/*---------------------------  Main  --------------------------*/
main()
/****************************************************************/
/*																*/														
/*																*/				
/****************************************************************/
{
// הצגת התפריט
float side_a=0,side_b=0,side_c=0;
char menu,rec_char,exit,buffer=0;
int rec_width,rec_length,i,j,capital_counter=0,lower_counter=0,numbers_counter=0,comma_counter=0,whites_counter=0,others_counter=0,total=0;

do
	{
		system("cls");
		printf("\n1.Rectangle\n\n2.Triangle\n\n3.Count Characters\n\n4.Exit\n\n");
		menu=getch();
	switch (menu)
		{
			case '1': //ציור המלבן
			system("cls");
			printf("Enter the dimention of the Rectangle. (Width (max 50) & Length)\n");
			scanf("%d%d",&rec_width,&rec_length);// קליטת ערכי רוחב ואורך
			while (rec_width>50)//תיקון חריגה
				{
					printf("Maximum length allowed is 50!\nPlease Enter new width.\n");
					scanf("%d",&rec_width);
										
				}
			printf("Ok. Now enter the component sign of the Rectangle.\n");//קליטת הסימן המרכיב
			rec_char=getch();
			system ("cls");
			for (j=1;j<=rec_width;j++) //לולאת רוחב
				{
					
					for (i=1;i<=rec_length;i++) //לולאת אורך
						{
							printf("%c",rec_char);
						
						}	
					printf("\n");
				}
			printf("\nPress any key\n");
			getch();
			break;
		
			case '2': //קליטת ערכי המשולש
			system ("cls");	
			printf("Enter 3 sides of a triange. (side a,side b,side c)\n");
			scanf("%f%f%f",&side_a,&side_b,&side_c);
			while (side_a+side_b<=side_c || side_a+side_c<=side_b || side_c+side_b<=side_a) 
				{		//בדיקת תקינות גדלי הצלעות
					printf("Sum of 2 sides should be grearter then the third!\nEnter new values:\n");
					scanf("%f%f%f",&side_a,&side_b,&side_c);
				}			
			
			if (side_a*side_a + side_b*side_b == side_c*side_c)  //בדיקה לפי פיתגורס האם המשולש ישר זוית
				printf("The trinangle is a 90 degree triangle.\n");
			if (side_a==side_b || side_a==side_c || side_b==side_c) //בדיקה האם המשולש הוא שווה צלעות או שווה שוקיים
				if (side_a==side_b && side_b==side_c) printf("The triangle is equilateral.\n");
				else printf("The triangle is isosceles.\n");
			else if (side_a*side_a + side_b*side_b != side_c*side_c) printf("The triangle is a simple triangle\n");//המשולש הוא משולש רגיל
			printf("\nPress any key\n");
			getch();
			break;
		
			case '3': //ספירת תווים
			system("cls");
			printf("Enter characters as much as you want, when you finished press CTRL+Z.\n");
			while (buffer !=EOF)	//לולאת קליטת נתונים
				{
					buffer=getchar();
					switch (buffer)
						{ //מיון נתונים 
							case EOF:
							break;
							case ';':	//ספירת סימני פיסוק		
							case '?':
							case ':':
							case '.':
							case ',':
								{	
									comma_counter++;
									break;
								}
							case ' ' ://ספירת רווחים טאבים ושורות חדשות
							case '\n':
							case '\t':
								{	
									whites_counter++;
									break;
								}
							default:
							if (buffer>='a' && buffer<='z') lower_counter++ ; //מיון אותיות גדלות וקטנות
							else
								if (buffer>='A' && buffer <='Z') capital_counter++;
								else if (buffer>='0' && buffer <='9') numbers_counter++; //מיון ספרות
									 else others_counter++; //שאר התווים
								
						}
							
				}
			total=capital_counter+lower_counter+numbers_counter+comma_counter+whites_counter+others_counter;
			system("cls");
			printf("Sum-Total\n\n");
			printf("Capital Letters=%d\nLower Letters=%d\nNumbers=%d\nComma=%d\nWhites=%d\nOthers=%d\n\nTotal chars=%d\n",capital_counter,lower_counter,numbers_counter,comma_counter,whites_counter,others_counter,total);
			getch();
			buffer=capital_counter=lower_counter=numbers_counter=comma_counter=whites_counter=others_counter=0;
			break; //ניקוי מונים לספירה חוזרת
			
			case '4'://יציאה מהתפריט
			printf("Are you sure? (Y/N)\n");//וידוא בקשת יציאה
			exit=getch();
			if (exit=='Y'||exit=='y') break;
			else //ביטול בקשת יציאה
				{
					menu=0;
					break;
				}
			default:
			printf("\nPlease Enter 1-4 Value !\n\nPress Any Key.\n");
			getch();
	
		}
	} 
	while (menu!='4');// יציאה מהלולאה

}


/*--------------------  Functions section  --------------------*/



/****************************    END   *************************/




