/***************************************************************/
/*						�������� �������						*/ 						
/*--------------------------------------------------------------*/
/*							                */         
/****************************************************************/
/*						:����:            ��:             ����	*/   
/****************************************************************/
/*																*/					
/*																*/					
/*																*/					
/*		������ ���� ���� ������ �������� ����� ��������			*/
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

power();//������� ����� �����
CalculatePowerInRange();//������� ������ ����� ����� ������	
GetUserRequest();//�������� ������ ������� 
DisplayResults();//�������� �����
clear();//�������� ������ ����� ������ ����


int basis[100],expon[100],result[100];//�������
int low,high,pwr;//������ ������� �� ������ �������� ��������
/*---------------------------  Main  --------------------------*/
void main()
/****************************************************************/
/*		������ ������ ���� �� ���� ����� ����� ���������		*/														
/*																*/				
/****************************************************************/
{

do //����� ������ �� ������ 3 ������ ������
	{
		GetUserRequest();
		if (low>0||high>0||pwr>0) //���� ������
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
power(x,y)//�������� ���� ����� ���� ����� ������� �����
{
int i,buffer=x;
	for (i=1;i<y;i++)
	{
		buffer*=x;
	}

if (y==0) return 1;
		else return buffer ;


}

CalculatePowerInRange(low,high,pwr)//������� ������ ���� �� ������ ������ �� ����� �� �� ���� �����
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
	while (result[i])//����� �� ��� �����
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


		
clear()//����� ���� �����
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




