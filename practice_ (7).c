/***************************************************************/
/*						����� ������ �� �����					*/ 						
/*--------------------------------------------------------------*/
/****************************************************************/
/*						:����:            ��:             ����	*/   
/****************************************************************/
/*																*/					
/*																*/					
/*																*/					
/*					������� ����� ���� ������					*/
/*		������ ����,���� �������,����� �����,���� ���� �������	*/
/*						������� �� ��� ����						*/						 										
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
// ���� ������
float side_a=0,side_b=0,side_c=0;
char menu,rec_char,exit,buffer=0;
int rec_width,rec_length,i,j,capital_counter=0,lower_counter=0,numbers_counter=0,comma_counter=0,whites_counter=0,others_counter=0,total=0,max_number=0,buffer_number=0,multi_value,multi_number=1;

do
	{
		system("cls");
		printf("\n1. Rectangle\n\n2. Triangle\n\n3. Count Characters\n\n4. Max\n\n5. Multiplication Table\n\n6. Exit\n\n");
		menu=getch();
	switch (menu)
		{
			case '1': //���� �����
			system("cls");
			printf("Enter the dimention of the Rectangle. (Width (max 50) & Length)\n");
			scanf("%d%d",&rec_width,&rec_length);// ����� ���� ���� �����
			while (rec_width>50)//����� �����
				{
					printf("Maximum length allowed is 50!\nPlease Enter new width.\n");
					scanf("%d",&rec_width);
										
				}
			printf("Ok. Now enter the component sign of the Rectangle.\n");//����� ����� ������
			rec_char=getch();
			system ("cls");
			for (j=1;j<=rec_width;j++) //����� ����
				{
					
					for (i=1;i<=rec_length;i++) //����� ����
						{
							printf("%c",rec_char);
						
						}	
					printf("\n");
				}
			printf("\nPress any key\n");
			getch();
			break;
		
			case '2': //����� ���� ������
			system ("cls");	
			printf("Enter 3 sides of a triange. (side a,side b,side c)\n");
			scanf("%f%f%f",&side_a,&side_b,&side_c);
			while (side_a+side_b<=side_c || side_a+side_c<=side_b || side_c+side_b<=side_a) 
				{		//����� ������ ���� ������
					printf("Sum of 2 sides should be grearter then the third!\nEnter new values:\n");
					scanf("%f%f%f",&side_a,&side_b,&side_c);
				}			
			
			if (side_a*side_a + side_b*side_b == side_c*side_c)  //����� ��� ������� ��� ������ ��� ����
				printf("The trinangle is a 90 degree triangle.\n");
			if (side_a==side_b || side_a==side_c || side_b==side_c) //����� ��� ������ ��� ���� ����� �� ���� ������
				if (side_a==side_b && side_b==side_c) printf("The triangle is equilateral.\n");
				else printf("The triangle is isosceles.\n");
			else if (side_a*side_a + side_b*side_b != side_c*side_c) printf("The triangle is a simple triangle\n");//������ ��� ����� ����
			printf("\nPress any key\n");
			getch();
			break;
		
			case '3': //����� �����
			system("cls");
			printf("Enter characters as much as you want, when you finished press CTRL+Z.\n");
			while (buffer !=EOF)	//����� ����� ������
				{
					buffer=getchar();
					switch (buffer)
						{ //���� ������ 
							case EOF:
							break;
							case ';':	//����� ����� �����		
							case '?':
							case ':':
							case '.':
							case ',':
								{	
									comma_counter++;
									break;
								}
							case ' ' ://����� ������ ����� ������ �����
							case '\n':
							case '\t':
								{	
									whites_counter++;
									break;
								}
							default:
							if (buffer>='a' && buffer<='z') lower_counter++ ; //���� ������ ����� ������
							else
								if (buffer>='A' && buffer <='Z') capital_counter++;
								else if (buffer>='0' && buffer <='9') numbers_counter++; //���� �����
									 else others_counter++; //��� ������
								
						}
							
				}
			total=capital_counter+lower_counter+numbers_counter+comma_counter+whites_counter+others_counter;
			system("cls");
			printf("Sum-Total\n\n");
			printf("Capital Letters=%d\nLower Letters=%d\nNumbers=%d\nComma=%d\nWhites=%d\nOthers=%d\n\nTotal chars=%d\n",capital_counter,lower_counter,numbers_counter,comma_counter,whites_counter,others_counter,total);
			getch();
			buffer=capital_counter=lower_counter=numbers_counter=comma_counter=whites_counter=others_counter=0;
			break; //����� ����� ������ �����
			
			case '4': //����� ���� �������
			system("cls");
			printf("Enter positive integer numbers. The first negative number will stop the input.\n");
			while (buffer_number>=0) //����� ����� �������
				{
					scanf("%d",&buffer_number);
					if (buffer_number > max_number) max_number=buffer_number ;
				}					
			printf("\n\nThe most high number is %d.\n",max_number);	//���� ����� ��������
			flushall () ;
			max_number=buffer_number=0; //����� ������ ������ ����
			getch();
			break;

			case '5': //������ ���� ��� ����
			system ("cls");
			printf("Enter an integer (max 20)\n");
			scanf("%d",&multi_value);
			while (multi_value>20)
				{
					printf("The number must be smaller or equal to 20! Enter new number\n");
					scanf("%d",&multi_value);//����� ����� �� ���� �-20
				}
			system ("cls");
			for (j=1;j<=multi_value;j++)//����� ������
				{
					for (i=1;i<=multi_value;i++)
						{
							printf("%4d",multi_number);//����� �������
							multi_number+=j;
						}
					multi_number=j+1;//���� ������� ���� ���� ����� �����
					printf("\n");
				}
			printf("\n\nPress Any Key\n");
			multi_number=1;//����� ����� ������ ����
			getch();
			break;
		
			case '6'://����� �������
			printf("Are you sure? (Y/N)\n");//����� ���� �����
			exit=getch();
			if (exit=='Y'||exit=='y') break;
			else //����� ���� �����
				{
					menu=0;
					break;
				}
			default:
			printf("\nPlease Enter 1-6 Value !\n\nPress Any Key.\n");
			getch();
	
		}
	} 
	while (menu!='6');// ����� �������

}


/*--------------------  Functions section  --------------------*/



/****************************    END   *************************/




