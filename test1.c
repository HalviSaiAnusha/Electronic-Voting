#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>
struct node1
{
	char name[10];
	long int uid;
	int age;
	char fname[10];
	char add[30];
	int pin;
	int pass;
	int flag;
	struct node1 *link1;
};
struct node2
{
	char party[10];
	int sym;
	int count;
	struct node2 *link2;
};
struct node1 *first1=NULL;
struct node2 *first2=NULL;
int co1=0,co2=0;
void append1()
{
	struct node1 *p1,*t1,*curr;
	char name[10],fname[10],add[10];
	int uid,age,pin,pass;
	//printf("enter ur details\n1.name\n2.uid\n3.age\n4.fathersname\n5.address\n6.pincode\n7.passwrord\n");
	printf("\tEnter your details\n");
	printf("\n");
	printf("\tName:");
	scanf("%s",name);
	printf("\n");
	printf("\tUID:");
	scanf("%ld",&uid);
	printf("\n");
	printf("\tAge:");
	scanf("%d",&age);
	printf("\n");
	printf("\tFather's Name:");
	scanf("%s",fname);
    printf("\n");
	printf("\tCity:");
	scanf("%s",add);
    printf("\n");
	printf("\tPincode:");
	scanf("%d",&pin);
    printf("\n");
	printf("\tPassword(In Numbers):");
	scanf("%d",&pass);
	//scanf("%s %ld %d %s %s %d %d",name,&uid,&age,fname,add,&pin,&pass);
		if(age>=18)
		{
		if(first1==NULL)
		{
		p1=(struct node1*)malloc(sizeof(struct node1));
		strcpy(p1->name,name);
		p1->uid=uid;
		p1->age=age;
		strcpy(p1->fname,fname);
		strcpy(p1->add,add);
		p1->pin=pin;
		p1->pass=pass;
		p1->link1=NULL;
		p1->flag=0;
		first1=p1;
		co1++;
        printf("\n\tRegistration Successful:)\n");
		}
		else
		{
		t1=first1;
		int flag=0;
		while(t1!=NULL)
		{
		    curr=t1;
			if(t1->uid==uid)
			{
				flag=1;
				break;
			}
			t1=t1->link1;
		}
			if(flag==0)
			{
				p1=(struct node1*)malloc(sizeof(struct node1));
				strcpy(p1->name,name);
				p1->uid=uid;
				p1->age=age;
				strcpy(p1->fname,fname);
				strcpy(p1->add,add);
				p1->pin=pin;
				p1->pass=pass;
				p1->link1=NULL;
				p1->flag=0;
				curr->link1=p1;
				co1++;
				printf("\tRegistration Successful:)\n");
			}
			else
			{
				printf("\n\tUID already exists!\n");
			}
		}
	}
	else
	{
		printf("Age is lesser than 18\nSo, you are not eligible to Vote\n");
	}
}
void traverse1()
{
    if(first1!=NULL){
    struct node1 *t1;
    t1=first1;
    while(t1!=NULL)
	{
    	if(first1==NULL)
    	{
    		printf("\n\tNo citizens are present\n");
    		break;
		}
		else
		{
	    	printf("\n\tName:%s\n\tUID:%d\n\tAge:%d\n\tFather's Name:%s\n\tAddress:%s\n\tPincode:%d\n\tPassword:%d\n",t1->name,t1->uid,t1->age,t1->fname,t1->add,t1->pin,t1->pass);
       		t1=t1->link1;
       	}
       	printf("\n\t-----------------------------------------------------\n\n");
	}
    }
    else{
        printf("\n\tNo voters present\n");
    }
}
void delete1()
{
	struct node1 *t1,*pre;
	int uid,flag=0;
	printf("\n\tEnter the UID of the person to be removed\n\t");
	scanf("%d",&uid);
	t1=first1;
	if(first1==NULL)
	{
		flag=2;
		printf("\tNo citizens present\n");
	}
	else if(t1->link1==NULL)
	{
		if(t1->uid==uid)
		{
			first1=NULL;
			free(t1);
			flag=1;
			co1--;
		}
	}
	else
	{
		while(t1!=NULL)
		{

			if(t1->uid==uid&&t1->link1==NULL)
			{
				flag=1;
				pre->link1=t1->link1;
				free(t1);
				co1--;
				break;
			}
			else if(t1->uid==uid&&t1->link1!=NULL)
			{
				flag=1;
				first1=t1->link1;
				free(t1);
			}
			else
			{
				pre=t1;
				t1=t1->link1;
			}
		}
	}
	if(flag==0)
	{
		printf("\tUID is not present to delete\n");
	}
	else{
        printf("\tDeleteion Successful\n");
	}
}
void append2()
{
	struct node2 *p2,*t2,*curr;
	char name[10];
	int sym,c;
	printf("\n\tName of the party:");
	scanf("%s",name);
	printf("\n\tSymbol:");
	scanf("%d",&sym);
	if(first2==NULL)
	{
		p2=(struct node2*)malloc(sizeof(struct node2));
		strcpy(p2->party,name);
		p2->sym=sym;
		p2->link2=NULL;
		p2->count=0;
		first2=p2;
		co2++;
	}
	else
	{
		t2=first2;
		int flag=0;
		while(t2!=NULL)
		{
		    curr=t2;
			if(t2->sym==sym)
			{
				flag=1;
				break;
			}
			t2=t2->link2;
		}
			if(flag==0)
			{
				p2=(struct node2*)malloc(sizeof(struct node2));
				strcpy(p2->party,name);
				p2->sym=sym;
				p2->link2=NULL;
				p2->count=0;
				curr->link2=p2;
				co2++;
			}
			else
			{
				printf("\n\tParty exists with same symbol\n");
			}
	}
}
void delete2()
{
	struct node2 *t2,*pre;
	int sym,flag=0;
	printf("\n\tEnter the party symbol of the party to be removed\n\t");
	scanf("%d",&sym);
	t2=first2;
	if(first2==NULL)
	{
		flag=2;
		printf("\n\tNo nominees are present to delete\n");
	}
	else if(t2->link2==NULL)
	{
		if(t2->sym==sym)
		{
			first2=NULL;
			free(t2);
			flag=1;
			co2--;
		}
	}
	else if(t2->sym==sym&&t2->link2!=NULL)
	{
		flag=1;
		first2=t2->link2;
		free(t2);
		co2--;
	}
	else
	{
		while(t2!=NULL)
		{
			if(t2->sym==sym)
			{
				flag=1;
				pre->link2=t2->link2;
				free(t2);
				co2--;
				break;
			}
			else
			{
				pre=t2;
				t2=t2->link2;
			}
		}
	}
	if(flag==0)
	{
		printf("\tSymbol is not present to delete the party\n");
	}
	else{
        printf("\tDeletion Successful\n");
	}
}
void traverse2()
{
    struct node2 *t2;
    t2=first2;
    if(t2==NULL){
        printf("\n\tNo Nominees!\n");
    }
    while(t2!=NULL)
	{
    	if(first2==NULL)
    	{
    		printf("no nominees are present\n");
    		break;
		}
		else
		{
	    	printf("\tName of the party:%s\n\tSymbol of the party:%d\n\tNumber of Votes:%d\n",t2->party,t2->sym,t2->count);
       		t2=t2->link2;
       	}
       	printf("\n\t-----------------------------------------------------\n\n");
	}
}
void traverse2_2()
{
    struct node2 *t2;
    t2=first2;
    if(t2==NULL){
        printf("\n\tNo Nominees!\n");
    }
    while(t2!=NULL)
	{
    	if(first2==NULL)
    	{
    		printf("No nominees are present\n");
    		break;
		}
		else
		{
	    	printf("\tName of the party:%s\n\tSymbol of the party:%d\n",t2->party,t2->sym);
       		t2=t2->link2;
       	}
       	printf("\n\t-----------------------------------------------------\n\n");
	}
}
void vote()
{
	struct node1 *t1;
	struct node2 *t2,*pre;
	int flag=0,p,sym,flag1=0;
	long int id;
	t1=first1;
	t2=first2;
	printf("\n\t");
	printf("Enter your Uid:");
	scanf("%ld",&id);
	printf("\n\t");
	printf("Enter your Password:");
	scanf("%d",&p);
	printf("\n");
	while(t1!=NULL)
	{
	struct node1 *curr=first1;
		while(curr!=NULL){
			if(curr->uid==id){
				flag1=1;
				break;
			}
			curr=curr->link1;
		}
		t1=curr;
		if(flag1)
		{
		if(t1->pass==p)
		{
			if(t1->flag==0){
            traverse2_2();
			printf("\n\tEnter the Symbol of the party to vote\n\t");
			scanf("%d",&sym);
			if(first2==NULL)
			{
				flag=2;
				printf("\n\tNo parties are present to vote\n");
			}
			else if(t2->link2==NULL)
			{
				if(t2->sym==sym)
				{
				t2->count=t2->count+1;
				flag=1;
				t1->flag=1;
				break;
				}
			}
			else
			{
				while(t2!=NULL)
				{
					if(t2->sym==sym)
					{
					flag=1;
					t2->count=t2->count+1;
					t1->flag=1;
					break;
					}
					t2=t2->link2;
				}
			}
			if(flag==0)
			{
				printf("\n\tSymbol is not present to vote to the party\n");
			}
		}
		else
		{
			printf("\n\tYou have already voted\n");
		}
	}
		else{
		printf("\n\tIncorrect password\n");
		}
	}
		else
		{
			printf("\n\tUID doesn't exist,Please register\n");
			break;
		}
		t1=t1->link1;
	}
}
void edit1(int uid)
{
	struct node1 *t1;
	int ch,c,c1,flag=0;
	char str[30];
	if(first1==NULL)
	{
		printf("\n\tNo voters to edit\n");
	}
	else
	{
		t1=first1;
		while(t1!=NULL)
		{
		if(t1->uid==uid)
		{
			flag=1;
			do
			{
			 	printf("\n\tPresent details\n\tName:%s\n\tUID:%d\n\tAge:%d\n\tFather's name:%s\n\tAddress:%s\n\tPincode:%d\n\tPassword:%d\n",t1->name,t1->uid,t1->age,t1->fname,t1->add,t1->pin,t1->pass);
		   		printf("\n\tEnter the details you want to change\n\t1.Name\n\t2.UID\n\t3.Age\n\t4.Father's Name\n\t5.Address\n\t6.Pincode\n\t7.Password\n\tEnter your choice\n\t");
		   		scanf("%d",&ch);
			   	switch(ch)
			   	{
		   			case 1:
					   printf("\tEnter new Name\n");
					   printf("\t");
					   scanf("%s",str);
					   strcpy(t1->name,str);
					   break;
					case 2:
						printf("\tEnter new UID\n");
						printf("\t");
						scanf("%d",&c);
						t1->uid=c;
						break;
					case 3:
						printf("\tEnter new Age\n");
						printf("\t");
						scanf("%d",&c);
						t1->age=c;
						break;
					case 4:
						printf("\tEnter new Father's Name\n");
						printf("\t");
						scanf("%s",str);
						strcpy(t1->fname,str);
						break;
					case 5:
						printf("\tEnter new Address\n");
						printf("\t");
						scanf("%s",str);
						strcpy(t1->add,str);
						break;
					case 6:
						printf("\tEnter new Pincode\n");
						printf("\t");
						scanf("%d",&c);
						t1->pin=c;
						break;
					case 7:
						printf("\tEnter new Password\n");
						printf("\t");
						scanf("%d",&c);
						t1->pass=c;
						break;
					default:
						printf("\tInvalid choice\n");
						break;
				}
				printf("\tDo you want to make any more changes 1 or 0 for exit\n");
				printf("\t");
				scanf("%d",&c1);
				}while(c1==1);
				break;
			}
				else
				{
					t1=t1->link1;
				}
		}
	}
	if(flag==0)
	{
		printf("\tPerson with the specified UID doesn't exist to edit\n");
	}
}
void edit2(int sym)
{
	struct node2 *t2;
	char str[10],c1;
	int ch,c,flag=0;
	if(first2==NULL)
	{
		printf("\tNo parties are present to display or edit\n");
	}
	else
	{
		t2=first2;
		while(t2!=NULL)
		{
			if(t2->sym==sym)
			{
				flag=1;
				do
				{
					printf("\n\tPresent details\n\tParty Name:%s\n\tSymbol:%d\n",t2->party,t2->sym);
					printf("\n\tEnter the details you want to change\n\t1.party name\n\t2.Symbol\n");
					printf("\t");
					scanf("%d",&ch);
			   	switch(ch)
			   	{
		   			case 1:
					   printf("\tEnter new Party Name\n");
					   printf("\t");
					   scanf("%s",str);
					   strcpy(t2->party,str);
					   break;
					case 2:
						printf("\tEnter new symbol\n");
						printf("\t");
						scanf("%d",&c);
						t2->sym=c;
						break;
					default:
						printf("\tInvalid choice\n");
						break;
				}
				printf("\tDo you want to make any more changes 1 or 0 for exit\n");
				printf("\t");
				scanf("%d",&c1);
				}while(c1==1);
				break;
				}
				else
				{
					t2=t2->link2;
				}
		}
	}
	if(flag==0)
	{
		printf("\tNo party found with the specified symbol to edit\n");
	}
}
int winner()
{
	struct node2 *t,*bigp;
	int big=-1;
	if(first2==NULL)
	{
		printf("\n\tNo Nominees are present\n");
	}
	else
	{
		t=first2;
		while(t!=NULL)
		{
			if(t->count>big)
			{
				big=t->count;
				bigp=t;
			}
			t=t->link2;
		}
	}
	t=first2;
	while(t!=NULL){
    if(t->count==big){
	printf("%\n\t****************** The winning party is %s-%d ******************\n",t->party,t->sym);
    }
	t=t->link2;
	}
}
void addtofile1()
{
	struct node1 *s=first1;
	FILE *f1;
	f1=fopen("detail.txt","ab");
	while(s!=NULL)
	{
		fprintf(f1,"%s\n",s->name);
		fprintf(f1,"%d\n",s->uid);
		fprintf(f1,"%d\n",s->age);
		fprintf(f1,"%s\n",s->fname);
		fprintf(f1,"%s\n",s->add);
		fprintf(f1,"%d\n",s->pin);
		fprintf(f1,"%d\n",s->pass);
	s=s->link1;
	}
	fclose(f1);
}
void addtofile2()
{
	struct node2 *s=first2;
	FILE *f1;
	f1=fopen("vote.txt","ab");
	while(s!=NULL)
	{
		fprintf(f1,"%s\n",s->party);
		fprintf(f1,"%d\n",s->sym);
		fprintf(f1,"%d\n",s->count);
		s=s->link2;
	}
	fclose(f1);
}
int main()
{
	int c,c1,c2,c3,c4,c5,c6,c7,c8;
	   SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN |
                                                            FOREGROUND_RED |
                                                            FOREGROUND_INTENSITY |
                                                            BACKGROUND_BLUE
        );
        c8=1;
	while(c8==1)
	{
	    system("cls");
	    printf("\n\n");
	    printf("%70s\n", "****************** WELCOME TO E-VOTING ******************\n");
	    printf("\n");
	    printf("%51s\n", "VOTING IS YOUR RIGHT\n");
	printf("\tContinue as ..... \n\t1.Voter\t\t2.Administrator\n\tPress Any key to Exit\n\tEnter your choice!\n");
	printf("\t");
	scanf("%d",&c);
	switch(c)
	{
		case 1:
        c3=1;
		while(c3==1)
		{
        system("cls");
        printf("\n\n");
        printf("%70s\n", "****************** WELCOME TO E-VOTING ******************\n");
	    printf("\n");
	    printf("%61s\n", "****************** VOTER ******************\n");
	    printf("\n");
		printf("\tEnter your Choice\n\t1.Register for E-Voting portal\n\t2.Vote for a party\n\t3.Back\n\t");
		scanf("%d",&c1);
		switch(c1)
		{
			case 1:
				append1();
				break;
			case 2:
			    if(first2!=NULL){
				vote();
				break;
			    }
			    else{
                    printf("\n\tNo Nominees Registered yet!\n");
                    break;
			    }
			default:
                c3=0;
                break;
		}
		printf("\n\tTo continue as voter press 1 or to exit press 0\n");
		printf("\t");
		scanf("%d",&c3);
		};
		break;
		case 2:
		do
		{
            printf("\n\tEnter Admin Password\n");
            printf("\t");
            int adm;
            scanf("%d",&adm);
            if(adm==1234){
		    system("cls");
            printf("%70s\n", "****************** WELCOME TO E-VOTING ******************\n");
            printf("\n");
            printf("%61s\n", "****************** ADMIN ******************\n");
			printf("\n\tEnter your choice\n\t1.Add a Nominee\n\t2.Display voter details\n\t3.Display Nominee details\n\t4.Edit Voter details\n\t5.Edit Nominee details\n\t6.Delete nominee\n\t7.Delete voter\n");
			printf("\t");
			scanf("%d",&c4);
			switch(c4)
			{
			     system("cls");
				case 1:
					printf("\n\tEnter the details\n");
					append2();
					break;
				case 2:
					printf("\n\tThe voters details are:\n\n");
					traverse1();
					break;
				case 3:
					printf("\n\tThe Nominee details are:\n\n");
					traverse2();
					break;
				case 4:
                    printf("\n\tThe voters details are:\n\n");
					traverse1();
					printf("\n\tEnter the UID of the person you want to edit\n\t");
					scanf("%d",&c5);
					edit1(c5);
					break;
				case 5:
				    printf("\n\tParties Details:\n");
				    traverse2();
					printf("\n\tEnter symbol of the party you want to edit\n\t");
					scanf("%d",&c6);
					edit2(c6);
					break;
				case 6:
				    traverse2();
					delete2();
					break;
				case 7:
				    traverse1();
					delete1();
					break;
				default:
					printf("\n\tInvalid Choice\n");
					break;
		}
			printf("\n\tTo continue as Admin press 1 or to exit press 0\n");
			printf("\t");
			scanf("%d",&c7);
			system("cls");
			}
            else{
            printf("\n\tIncorrect Password for Admin\n");
            printf("\n\tTo continue as Admin press 1 or to exit press 0\n");
            printf("\t");
			scanf("%d",&c7);
			system("cls");
            }
			}while(c7==1);
			break;
		default:
			c8=0;
			break;
		printf("\n\tFor Main Menu press 1 or to exit press 0\n");
		printf("\t");
		scanf("%d",&c8);
	}
	}
	winner();
	addtofile1();
	addtofile2();
	return 0;
}
