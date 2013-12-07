
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>




/*---------  Functions/Functions-Declarations section  --------*/

generate();//��������� ����� �� �� ������� ������� ������ ���� �����
validation();//�������� ����� ���� ������ �� ��� ����
check();//�������� ���� 2 ������ ������ ����� ��� �����
randomize();//�������� ����� �����
rand_reset();//�����  �������� �����
calculate();//�������� ���� �� ����� ��� �� ��� ����� ������
ask();//�������� ����� �����
eliminate();//�������� ����� ������ �� ����������
func_a();//���� ����
func_c();//������ ���� ���� ������ ����
func_b();//����� ���� ���� ������� ����
func_d();//����� ���� ���� ����� ����
func_d_run();//�������� ���� 
demo();//����� �� ���������
reset();//�������� ����� �����
submenu();//�������� �� �����


//���� ������� ������� �����
int serial [2][5040];


/*---------------------------  Main  --------------------------*/
void main()//������ �����

{
	
int menu;

do
{
	system("cls");	
	printf("\n1. Normal Game: User against the machine.\n");
	printf("\n2. Computer choose number,user guess it.\n");
	printf("\n3. User choose number,computer guess it.\n");
	printf("\n4. Checking quality of algorithm.\n");
	printf("\n5. exit\n");
	scanf("%d",&menu);

	switch(menu)
	{
	case 1:
		system("cls");
		func_a();
		getch();
		break;
	case 2:
		system("cls");
		func_b();
		break;
	case 3:
		system("cls");
		func_c();
		getch();
		break;
	case 4:
		submenu();
		break;
	case 5:
		system("cls");
		break;
	default:
	printf("\nPlease choose 1 of the options above\n");
	getch();
		break;
	}
}
	while (menu!=5);

	
	
}






/*--------------------  Functions section  --------------------*/

submenu()
{
	int menu;
		do
		{
		system("cls");
		printf("\n1. Demostration of the game.\n");
		printf("\n2. Auto run.\n");
		printf("\n3. back to main menu.\n");
		scanf("%d",&menu);

	switch(menu)
	{
	case 1:
		system("cls");
		demo();
		break;
	case 2:
		system("cls");
		func_d_run();
		getch();
		break;
	case 3:
		system("cls");
		return 1;
	default:
		printf("\nPlease choose 1 of the options above\n");
		getch();
	}

		}
		while (menu!=3);
		return 0;
}


func_a()
{
	int guess=0,answer,i;
	int chosen,cmp_index=0,user_index=0,user_guess,cmp_answer;
	
	
	reset();//����� ����
	generate();//��������� ����� ������ ������ ������ ���� �����
	rand_reset();
	guess=randomize();//���� ���� �� ���� ������
	chosen=randomize();//����� ���� ����

	for(i=0;guess!=-1;i++)//����� ���-���
	{

	//��� ������
	user_index++;//���� �����
	printf("\nUser turn:\nTry to guess my number.\n(%d)\n",user_index);
	do
		{
		scanf("%d",&user_guess);//����� ����� ������
		if (!validation(user_guess))//����� ��� ����� ������ ��� ���� ����
				{
				printf("\nThis can't be my number.\nTry Again.\n\n");
				user_index++;//����� ���
				printf("(%d)\n",user_index);
				}
		}
	while(!validation(user_guess));

	//���� ���� ����
	cmp_answer=check(user_guess,chosen);
		if (cmp_answer<10) printf("0");

		if (cmp_answer==40) 
		{
			printf("\nThat my number!!!\nYou Win!\n\n");
			getch();
			return 1;
		}
		printf("%d is the answer for your guess.\n\n",cmp_answer);
		getch();
		

	//��� �����
	cmp_index++;
	printf("\nMy turn:\n");
	if (guess<1000) printf("0");//����� ������ ����� �����
	printf("%d\nIs this your number?\n(%d)\n",guess,cmp_index);	
	answer=ask();//����� ������ �������
		if (answer==40)//����� ����
			{
				printf("I win !!!\n");
				if (chosen<1000) printf("0");
				printf("%d was my number \n",chosen);
				return 1;
			}

	
	guess=calculate(answer,guess);//����� ���� �� ������ ��� ���
	}



	if (guess==-1)//����� �����
			{
				printf("You are mistaking your calculation,\nOr your number is illegal!\n\n");
				getch();
			}
	return 0;
}


func_b()
{
int chosen,guess,ok=0,answer=0,i=1;
reset();
rand_reset();
chosen=randomize();
printf("I choose my number.\nNow,try to guess it.\n\n");
printf("If you want to exit, type 0\n");
while(answer!=40)
	{
		do
		{
			printf("Guess no. (%d)\n",i);
			scanf("%d",&guess);
			if (guess==0) return 1;
			i++;
			if (!validation(guess))	//����� ������ �����
			printf("\nThis can't be my number.\nTry Again.\n\n");
					
		}
		while (!validation(guess));	
		
		answer=check(guess,chosen);//����� ������ ������
		if (answer<10) printf("0");
		if (answer==40) 
		{
			printf("\nThat my number!!!\n\n");	
			getch();
			return 1;
		}
		printf("%d is the answer for your guess.\n\n",answer);
		
	}
return 0;
}


demo()

	{

int guess,answer,i,chosen,ok=0;
	reset();//����� ����
	generate();//��������� ����� ������ ������ ������ ���� �����
	rand_reset();
	guess=randomize();//����� ���� ����
	rand_reset();
	chosen=randomize();//����� ���� ����
	if (chosen<1000) printf("0");
	printf("%d is the chosen number \n",chosen);
	printf("\nmy guesses:\n\n");
	if (guess<1000) printf("0");
	printf("%d ?\n",guess);
	answer=check(guess,chosen);//����� ��� ��� ����� ������
	if (answer<10) printf("0");
	printf("%d is the answer. \n\n",answer);
	guess=calculate(answer,guess);//����� ���
	if (guess<1000) printf("0");
	printf("%d ?\n",guess);
	for(i=1;guess!=-1;i++)//����� ���� �������
	{
		answer=check(guess,chosen);//����� ��� �����
		if (answer<10) printf("0");
		printf("%d is the answer. \n\n",answer);
		if (answer==40)//����� ����
		{
			printf("Total guesses: %d\n",i+1);
			getch();
			return 1;
		}

		guess=calculate(answer,guess);//����� ���� �� ����� ���
		if (guess<1000) printf("0");
		printf("%d ?\n",guess);	
	}		
	return 0;
	}


func_d_run()
{
int i,runs,average,total=0,guesses,min_g=10,max_g=1,min_i,max_i;
printf("Please enter number of runs (at least once)\n");
do
{
scanf("%d",&runs);
}
while (runs<1);
rand_reset();
for(i=0;i<runs;i++)
	{
		guesses=func_d();
		if (func_d()==0) return 0;
		total+=guesses;
		if (max_g<guesses)
			{
				max_g=guesses;
				max_i=i;
			}

		if (min_g>guesses)
			{
				min_g=guesses;
				min_i=i;
			}
	}	
average=total/runs;
printf("\nsummary:\nTotal runs:%d\n%d guesses\nMax guesses:%d (Run number %d)\nMin Guesses:%d (Run number %d)\nAverage guesses:%d\n",runs,total,max_g,max_i,min_g,min_i,average);

return 1;
}

reset()
{
	int i;
	for(i=0;i<5040;i++)
		serial[1][i]=0;
}

func_d()
{
	
	int guess,answer,i,chosen,ok=0;
	reset();//����� ����
	generate();//��������� ����� ������ ������ ������ ���� �����
	guess=randomize();//����� ���� ����
	chosen=randomize();//����� ���� ����
	answer=check(guess,chosen);//����� ��� ��� ����� ������
	guess=calculate(answer,guess);//����� �����
	for(i=1;guess!=-1;i++)//����� ���� �������
	{
		answer=check(guess,chosen);//����� ��� �����
		if (answer==40)//����� ����
				return i;//���� ��������

		guess=calculate(answer,guess);	
	}
	if (guess==-1)//����� �����
			{
				printf("You are mistaking your calculation,\nOr your number is illegal!\n\n");
				getch();
			}
	return 0;

	
}











func_c()
{
	int guess,answer,i;
	reset();//����� ����
	generate();//��������� ����� ������ ������ ������ ���� �����
	rand_reset();
	guess=randomize();
	if (guess<1000) printf("0");
	printf("%d\nIs this your number?\n",guess);	
	answer=ask();//����� ������ �������
		if (answer==40)//����� ����
			{
				printf("I win !!!\n");
				return 1;
			}
	guess=calculate(answer,guess);

	for(i=0;i<20;i++)//����� ���� �������
	{
		system("cls");
		if (guess==-1)//����� �����
			{
				system("cls");
				printf("You are mistaking your calculation,\nOr your number is illegal!\n\n");
				break;
			}

		if (guess<1000) 
			printf("0");//����� ������ ����� �����

		printf("%d\nIs this your number?\n",guess);//���� �����
		answer=ask();
		if (answer==40)//����� ����
			{
				printf("I win !!!\n");
				return 1;
			}
		guess=calculate(answer,guess);	
	}
	return 0;
}

generate()//�������� ����� ������� �������
{
int number,i=0;
int num[4]={0};

for (number=0;number<9999;number++)// ����� ����� �������
			{
				
				if (validation ( number ))
						{
							serial[0][i]=number;
							i++;
						}
				
			}

}

validation(number)//�������� ����� 4 ����� ������� ��� ��� ����� ���� �������� ��� ������
{
	int num[4];

	if (number<123||number>9876) return 0;
	num[3]=(number)%10;
	num[2]=(number/10)%10;
	num[1]=(number/100)%10;
	num[0]=(number/1000);
	
if ((num[0]==num[1])||(num[0]==num[2])||(num[0]==num[3])||(num[1]==num[2])||(num[1]==num[3])||(num[2]==num[3])) 
return 0;
 else return 1;
}


check(number1,number2)//�������� ��� �����
{
	int i,num[2][4],b=0,p=0;


	for (i=0;i<4;i++)//����� �������
	{
		num[0][i]=number1%10,num[1][i]=number2%10;
		number1/=10,number2/=10;
	}

	for (i=0;i<4;i++)//����� ���
	{
		if (num[0][i]==num[1][i])
			b++;
	}
	
	for (i=1;i<4;i++)//����� �����
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

rand_reset()
{

srand( (unsigned)time( NULL ) );

}

randomize()//�������� ���� ���� ����� ���� ������� �������
{

int number;
static last;

while (!validation(number)||number==last)
		number=rand();
last=number;
return number;

}

calculate(answer,guess)//�������� ���� �� ����� ������,���� ������ �� ����� ���

{
int i,ok=0;
eliminate(answer,guess);//���� ������ �� ����������
for (i=0;!ok;i++)
	{
		if (i==5040)//����� ����� ������ �������
			return -1;
		if (serial[1][i]==1)//���� ����� �"� �������� �� ��� ������
			continue;
		ok=1;
	}
i--;//���� �� ������ ������� ������� �� ������
serial[1][i]=1;	//���� �� ����� ��� ���� ���
return serial[0][i];//����� �� ����� ����������
}

ask()//����� ������ �������
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
	int i;
		
	for (i=0;i<5040;i++)
	{

		if ((check(serial[0][i],guess)!=answer)&&serial[1][i]==0)
		{
			serial[1][i]=1;
		}

	}

}

/****************************    END   *************************/
