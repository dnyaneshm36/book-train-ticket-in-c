#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef enum{FAILURE,SUCCESS}status_code;
typedef struct passenger_tag
{
	char name[50];
	int id;
	char address[50];
	char phone_no[15];
	int age;
	char preference[15];
	struct passenger_tag *prev;
	struct passenger_tag *next;
}passenger_type;
typedef struct seat_tag
{
	int booked;
	int count;
	int id;
	int id2;
}seat_type;
typedef struct coach_tag
{
	int count;
	seat_type lower[10];
	seat_type middle[10];
	seat_type upper[10];
	seat_type side_lower[5];
	seat_type side_upper[5];
	passenger_type* passenger_ptr;
	passenger_type* rac_list;
	passenger_type* waiting_list;
	struct coach_tag *next;
	struct coach_tag *prev;
}coach_type;
typedef struct train_tag
{
	int count;
	struct train_tag * prev;
	struct train_tag * next;
	coach_type * coach_ptr;

}train_type;
passenger_type*generatepassenger()
{
	passenger_type* newnode;
	newnode=(passenger_type*)malloc(sizeof(passenger_type));
	newnode->name[0]='\0';
	newnode->id=0;
	newnode->address[0]='\0';
	newnode->phone_no[0]='\0';
	newnode->age=0;
	newnode->preference[0]='\0';
	newnode->next=NULL;
	newnode->prev=NULL;
}
passenger_type* addpassenger(passenger_type* plist,passenger_type* pass)
{
	passenger_type* ptr,*newnode;
	ptr=plist;
	newnode=generatepassenger();
	if(ptr==NULL)
	{
		newnode->age=pass->age;
		newnode->id=pass->id;
		strcpy(newnode->name,pass->name);
		strcpy(newnode->address,pass->address);
		strcpy(newnode->phone_no,pass->phone_no);
		strcpy(newnode->preference,pass->preference);
		plist=newnode;	
	}
	else
	{
		
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		newnode=generatepassenger();
		newnode->age=pass->age;
		newnode->id=pass->id;
		strcpy(newnode->name,pass->name);
		strcpy(newnode->address,pass->address);
		strcpy(newnode->phone_no,pass->phone_no);
		strcpy(newnode->preference,pass->preference);		
		ptr->next=newnode;
		newnode->prev=ptr;
	}
	return plist;
}
passenger_type* deletepassenger(passenger_type *plist,passenger_type* pass)
{
	passenger_type* prevnode,*nextnode,*temp;
	if(pass!=NULL)
	{
	
	temp=pass;
	prevnode=pass->prev;
	nextnode=pass->next;
		if(nextnode==NULL)
		{

			prevnode->next=NULL;
			free(pass);
		}
		else if (prevnode==NULL)
		{
			
			nextnode->prev=NULL;
			plist=nextnode;
			free(pass);
		}
		else
		{
			nextnode->prev=prevnode;
			prevnode->next=nextnode;
			free(pass);
		}
	}
	else
	{
		printf("\nnode is not found ");
	}
	return plist;
}
coach_type* getarequiredcoachformtrain(train_type* tptr,int train_count,int coach_id)
{
	int i,j;
	train_type* ptr;
	coach_type* cptr;
	coach_type* ret_val;
	ptr=tptr;
	if(ptr!=NULL)
	{
			while(ptr!=NULL&&ptr->count!=train_count)
			{
				ptr=ptr->next;
			}
			if(ptr->coach_ptr==NULL)
			{
				printf("\n\t ---coach is not found");
			}
			else{	
					cptr=ptr->coach_ptr;
					while(cptr!=NULL&&cptr->count!=coach_id)
					{
						cptr=cptr->next;
					}
					if(cptr==NULL)
					{
						printf("\n\t ---coach number is not found");
					}
					ret_val=cptr;						
		 	  	}
		return ret_val;
	}	
}
passenger_type* passengerlist(train_type* tptr,int train_count,int coach_id)
{
	int i,j;
	train_type* ptr;
	coach_type* cptr;
	passenger_type* ret_val;
	ptr=tptr;
	if(ptr!=NULL)
	{
			while(ptr!=NULL&&ptr->count!=train_count)
			{
				ptr=ptr->next;
			}
			if(ptr->coach_ptr==NULL)
			{
				printf("\n\t ---coach is not found");
			}
			else{	
					cptr=ptr->coach_ptr;
					while(cptr!=NULL&&cptr->count!=coach_id)
					{
						cptr=cptr->next;
					}
					if(cptr==NULL)
					{
						printf("\n\t ---coach number is not found");
					}
					ret_val=cptr->passenger_ptr;						
		 	  	}
		return ret_val;
	}	
}
passenger_type* displayplist(passenger_type* plist)
{
	passenger_type* ptr;
	ptr=plist;
	while(ptr!=NULL)
	{
		printf("\nid=%d  & age=%d\n",ptr->id,ptr->age);
		puts(ptr->name);
		puts(ptr->address);
		puts(ptr->phone_no);
		puts(ptr->preference);
		ptr=ptr->next;		
	}
	return plist;
}
void intitialise_seat(coach_type * ptr)
{
	int i;
	for(i=0;i<10;i++)
	{
		ptr->lower[i].booked=0;
		ptr->middle[i].booked=0;
		ptr->upper[i].booked=0;
	}
	for(i=0;i<5;i++)
	{
		ptr->side_lower[i].booked=0;
		ptr->side_upper[i].booked=0;	
	}
		for(i=0;i<10;i++)
		{
			ptr->lower[i].count=0;
			ptr->middle[i].count=0;
			ptr->upper[i].count=0;
		}
		for(i=0;i<5;i++)
		{
			ptr->side_lower[i].count=0;
			ptr->side_upper[i].count=0;	
		}
		for(i=0;i<10;i++)
		{
			ptr->lower[i].count=0;
			ptr->middle[i].count=0;
			ptr->upper[i].count=0;
		}
		for(i=0;i<5;i++)
		{
			ptr->side_lower[i].count=0;
			ptr->side_upper[i].count=0;	
		}
		for(i=0;i<10;i++)
		{
			ptr->lower[i].id=0;
			ptr->middle[i].id=0;
			ptr->upper[i].id=0;
		}
		for(i=0;i<5;i++)
		{
			ptr->side_lower[i].id=0;
			ptr->side_upper[i].id=0;	
	    }
		for(i=0;i<10;i++)
		{
			ptr->lower[i].id2=0;
			ptr->middle[i].id2=0;
			ptr->upper[i].id2=0;
		}
		for(i=0;i<5;i++)
		{
			ptr->side_lower[i].id2=0;
			ptr->side_upper[i].id2=0;	
	    }
}
coach_type *makecoach()
{
	coach_type* newnode;
	newnode=(coach_type*)malloc(sizeof(coach_type));
	newnode->count=-1;
	intitialise_seat(newnode);
	newnode->passenger_ptr=NULL;
	newnode->rac_list=NULL;
	newnode->waiting_list=NULL;
	newnode->next=NULL;
	newnode->prev=NULL;
}
status_code addCouch(train_type* train_ptr,int train_count)
{
	status_code sc=SUCCESS;
	train_type *tptr;
	coach_type *ptr,*newnode;
	tptr=train_ptr;
	int count=1;

	if(tptr!=NULL)
	{
			while(tptr!=NULL&&tptr->count!=train_count)
			{
				tptr=tptr->next;
			}
			if(tptr==NULL)
			{
				printf("\n\t---train number is not found");
				sc=FAILURE;
			}
		newnode=makecoach();
		ptr=tptr->coach_ptr;
		if(ptr==NULL)
		{
			newnode->count=count;
			ptr=newnode;
			tptr->coach_ptr=ptr;
		}
		else
		{
			count++;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
				count++;
			}
			newnode->count=count;
			ptr->next=newnode;
			newnode->prev=ptr;
		}
	}
	else
	{
		sc=FAILURE;
	}	
	return sc;
}
train_type *generatetrain()  
{
	train_type *newnode;
	newnode=(train_type *)malloc(sizeof(train_type));
	newnode->count=0;
	newnode->coach_ptr=NULL;
	newnode->next=NULL;
	newnode->prev=NULL;
	return newnode;
}
train_type* addTrain(train_type *train_ptr)
{
	train_type* newnode,*tptr=train_ptr;
	int count=1;
	if(tptr!=NULL)
	{
		count++;
		while(tptr->next!=NULL)
		{
			tptr=tptr->next;
			count++;
		}
		newnode=generatetrain();
		newnode->count=count;
		newnode->coach_ptr=NULL;
		tptr->next=newnode;
		newnode->prev=tptr;
	}
	else
	{
		newnode=generatetrain();
		newnode->count=count;
		newnode->coach_ptr=NULL;
		train_ptr=newnode;
		
	}
	return train_ptr;
}
void displayCouchdata(train_type* tptr,int train_count,int coach_id)
{
	int i,j;
	train_type* ptr=NULL;
	coach_type* cptr=NULL;
	ptr=tptr;
	if(ptr!=NULL)
	{
			while(ptr!=NULL&&ptr->count!=train_count)
			{
				ptr=ptr->next;
			}
			if(ptr->coach_ptr==NULL)
			{
				printf("\n\t ---coach is not found");
			}
			else{	
					cptr=ptr->coach_ptr;
					while(cptr!=NULL&&cptr->count!=coach_id)
					{
						cptr=cptr->next;
					}
					if(cptr==NULL)
					{
						printf("\n\t ---coach number is not found");
					}
					printf("\n coach_number is %d",cptr->count);				
					printf("\n ----lower birth");
					for(i=0;i<10;i++)
					{
						if(cptr->lower[i].booked==1)
						{
							printf("\n%d is booked",i+1);
						}
						else if(cptr->lower[i].booked==0)
						{
							printf("\n%d is not Booked",i+1);
						}
						if(cptr->lower[i].count!=0)
						{
						
							printf("\t%d person's",cptr->lower[i].count);
						 	printf("\tid:-");
							for(j=0;j<cptr->lower[i].count;j++)
							{
								printf("%d ",cptr->lower[i].id);
							}
				    	}
					}					
					printf("\n\n\n ----middle birth");
					for(i=0;i<10;i++)
					{
						if(cptr->middle[i].booked==1)
						{
							printf("\n%d is booked",i+1);
						}
						else if(cptr->middle[i].booked==0)
						{
							printf("\n%d is not Booked",i+1);
						}
						if(cptr->middle[i].count!=0)
						{
							printf("\t%d person's",cptr->middle[i].count);
						 	printf("\tid:-");
							for(j=0;j<cptr->middle[i].count;j++)
							{
								printf("%d ",cptr->middle[i].id);
							}
						}
					}							
					printf("\n\n\n ----upper birth");
					for(i=0;i<10;i++)
					{
						if(cptr->upper[i].booked==1)
						{
							printf("\n%d is booked",i+1);
						}
						else if(cptr->upper[i].booked==0)
						{
							printf("\n%d is not Booked",i+1);
						}
						if(cptr->upper[i].count!=0)
						{
							printf("\t%d person's",cptr->upper[i].count);
						 	printf("\tid:-");
							for(j=0;j<cptr->upper[i].count;j++)
							{
								printf("%d ",cptr->upper[i].id);
							}
						}
					}
					printf("\n\n\n ----side_lower birth");
					for(i=0;i<5;i++)
					{
						if(cptr->side_lower[i].booked==1)
						{
							printf("\n%d is booked",i+1);
						}
						else if(cptr->side_lower[i].booked==0)
						{
							printf("\n%d is not Booked",i+1);
						}
						if(cptr->side_lower[i].count!=0)
						{
						printf("\t%d person's",cptr->side_lower[i].count);
						 	printf("\tid:-");
						//	for(j=0;j<cptr->side_lower[i].count;j++)
							{
								printf("%d ",cptr->side_lower[i].id);
								printf(", %d",cptr->side_lower[i].id2);
							}
						}
					}
					printf("\n\n\n ----side_upper birth");
					for(i=0;i<5;i++)
					{
						if(cptr->side_upper[i].booked==1)
						{
							printf("\n%d is booked",i+1);
						}
						else if(cptr->side_upper[i].booked==0)
						{
							printf("\n%d is not Booked",i+1);
						}
						if(cptr->side_upper[i].count!=0)
						{
						printf("\t%d person's",cptr->side_upper[i].count);
						 	printf("\tid:-");
							for(j=0;j<cptr->side_upper[i].count;j++)
							{
								printf("%d ",cptr->side_upper[i].id);
							}
						}
					}
					
					printf("\n\n\t passengger for this coach is \n");
					cptr->passenger_ptr=displayplist(cptr->passenger_ptr);
					
		 	  	}
	}
	else
	{
		printf("\n\t-----train is not present ");
	}
	
}
train_type* displaytrain(train_type* tptr)
{
	train_type* ptr;
	ptr=tptr;
	while(ptr!=NULL)
	{
		printf("\ntrain_no %d",ptr->count);
		if(ptr->next!=NULL)
		{
			printf("\tnext train no is %d",ptr->next->count);
		}
		if(ptr->prev!=NULL)
		{
			printf("\tprev train no is %d",ptr->prev->count);
		}
		ptr=ptr->next;
	}
	return tptr;
}
status_code perfectseat(coach_type* cptr,passenger_type* ptr)
{
	int i,stop;
	status_code sc;
	sc=FAILURE;
	if(strcmp(ptr->preference,"lower")==0)
	{
		stop=0;
	//	do{
				for(i=0;i<10&&stop==0;i++)
				{
					if(cptr->lower[i].booked==0)
					{
						cptr->lower[i].count=1;
						cptr->lower[i].id=ptr->id;
						cptr->lower[i].booked=1;
					 stop=1;
					 sc=SUCCESS;	
					}
				}
				if(sc==FAILURE)
				{
					for(i=0;i<10&&stop==0;i++)
					{
						if(cptr->middle[i].booked==0)
						{
							cptr->middle[i].count=1;
							cptr->middle[i].id=ptr->id;
							cptr->middle[i].booked=1;
						 stop=1;
						 sc=SUCCESS;	
						}
					}
					if(sc==FAILURE)
					{
						for(i=0;i<10&&stop==0;i++)
						{
							if(cptr->upper[i].booked==0)
							{
								cptr->upper[i].count=1;
								cptr->upper[i].id=ptr->id;
								cptr->upper[i].booked=1;
							 stop=1;
							 sc=SUCCESS;	
							}
						}
						if(sc==FAILURE)
						{
							for(i=0;i<5&&stop==0;i++)
							{
								if(cptr->side_lower[i].booked==0)
								{
									cptr->side_lower[i].count=1;
									cptr->side_lower[i].id=ptr->id;
									cptr->side_lower[i].booked=1;
								 stop=1;
								 sc=SUCCESS;	
								}
							}
							if(sc==FAILURE)
							{
								for(i=0;i<5&&stop==0;i++)
								{
									if(cptr->side_upper[i].booked==0)
									{
										cptr->side_upper[i].count=1;
										cptr->side_upper[i].id=ptr->id;
										cptr->side_upper[i].booked=1;
									 stop=1;
									 sc=SUCCESS;	
									}
								}
								
							}							
						}						
					}
				}
				
	//	 cptr=cptr->next;
	//	}while(cptr!=NULL&&stop==0)
	}
	else if(strcmp(ptr->preference,"middle")==0)
	{
		stop=0;
	//	do{
				for(i=0;i<10&&stop==0;i++)
				{
					if(cptr->middle[i].booked==0)
					{
						cptr->middle[i].count=1;
						cptr->middle[i].id=ptr->id;
						cptr->middle[i].booked=1;
					 stop=1;
					 sc=SUCCESS;	
					}
				}
				if(sc==FAILURE&&(ptr->age<15||ptr->age>60))
				{
					for(i=0;i<10&&stop==0;i++)
					{
						if(cptr->lower[i].booked==0)
						{
							cptr->lower[i].count=1;
							cptr->lower[i].id=ptr->id;
							cptr->lower[i].booked=1;
						 stop=1;
						 sc=SUCCESS;	
						}
					}
					if(sc==FAILURE)
					{
						for(i=0;i<10&&stop==0;i++)
						{
							if(cptr->upper[i].booked==0)
							{
								cptr->upper[i].count=1;
								cptr->upper[i].id=ptr->id;
								cptr->upper[i].booked=1;
								stop=1;
								sc=SUCCESS;	
							}
						}
						if(sc==FAILURE)
						{
							for(i=0;i<10&&stop==0;i++)
							{
								if(cptr->lower[i].booked==0)
								{
									cptr->lower[i].count=1;
									cptr->lower[i].id=ptr->id;
									cptr->lower[i].booked=1;
									stop=1;
									sc=SUCCESS;	
								}
							}
							if(sc==FAILURE)
							{
								for(i=0;i<5&&stop==0;i++)
								{
									if(cptr->side_lower[i].booked==0)
									{
										cptr->side_lower[i].count=1;
										cptr->side_lower[i].id=ptr->id;
										cptr->side_lower[i].booked=1;
										stop=1;
										sc=SUCCESS;	
									}
								}
								if(sc==FAILURE)
								{
									for(i=0;i<5&&stop==0;i++)
									{
										if(cptr->side_upper[i].booked==0)
										{
											cptr->side_upper[i].count=1;
											cptr->side_upper[i].id=ptr->id;
											cptr->side_upper[i].booked=1;
											stop=1;
											sc=SUCCESS;	
										}
									}
								}								
							}							
						}						
					}					
				}
	//	 cptr=cptr->next;
	//	}while(cptr!=NULL&&stop==0)
	}
	else if(strcmp(ptr->preference,"upper")==0)
	{
		stop=0;
	//	do{
				for(i=0;i<10&&stop==0;i++)
				{
					if(cptr->upper[i].booked==0)
					{
						cptr->upper[i].count=1;
						cptr->upper[i].id=ptr->id;
						cptr->upper[i].booked=1;
					 stop=1;
					 sc=SUCCESS;	
					}
					
				}
				if(sc==FAILURE&&(ptr->age<15||ptr->age>60))
				{
					for(i=0;i<10&&stop==0;i++)
					{
						if(cptr->lower[i].booked==0)
						{
							cptr->lower[i].count=1;
							cptr->lower[i].id=ptr->id;
							cptr->lower[i].booked=1;
						 stop=1;
						 sc=SUCCESS;	
						}
					}
					if(sc==FAILURE)
					{
						for(i=0;i<10&&stop==0;i++)
						{
							if(cptr->middle[i].booked==0)
							{
								cptr->middle[i].count=1;
								cptr->middle[i].id=ptr->id;
								cptr->middle[i].booked=1;
								stop=1;
								sc=SUCCESS;	
							}
						}
						if(sc==FAILURE)
						{
							for(i=0;i<10&&stop==0;i++)
							{
								if(cptr->lower[i].booked==0)
								{
									cptr->lower[i].count=1;
									cptr->lower[i].id=ptr->id;
									cptr->lower[i].booked=1;
									stop=1;
									sc=SUCCESS;	
								}
							}
							if(sc==FAILURE)
							{
								for(i=0;i<5&&stop==0;i++)
								{
									if(cptr->side_lower[i].booked==0)
									{
										cptr->side_lower[i].count=1;
										cptr->side_lower[i].id=ptr->id;
										cptr->side_lower[i].booked=1;
										stop=1;
										sc=SUCCESS;	
									}
								}
								if(sc==FAILURE)
								{
									for(i=0;i<5&&stop==0;i++)
									{
										if(cptr->side_upper[i].booked==0)
										{
											cptr->side_upper[i].count=1;
											cptr->side_upper[i].id=ptr->id;
											cptr->side_upper[i].booked=1;
											stop=1;
											sc=SUCCESS;	
										}
									}
								}								
							}							
						}						
					}					
				}
	//	 cptr=cptr->next;
	//	}while(cptr!=NULL&&stop==0)
	}
	else if(strcmp(ptr->preference,"side_lower")==0)
	{
		stop=0;
	//	do{
				for(i=0;i<5&&stop==0;i++)
				{
					if(cptr->side_lower[i].booked==0)
					{
						cptr->side_lower[i].count=1;
						cptr->side_lower[i].id=ptr->id;
						cptr->side_lower[i].booked=1;
					 stop=1;
					 sc=SUCCESS;	
					}	
				}
				if(sc==FAILURE&&(ptr->age<15||ptr->age>60))
				{
					for(i=0;i<10&&stop==0;i++)
					{
						if(cptr->lower[i].booked==0)
						{
							cptr->lower[i].count=1;
							cptr->lower[i].id=ptr->id;
							cptr->lower[i].booked=1;
						 stop=1;
						 sc=SUCCESS;	
						}
					}
					if(sc==FAILURE)
					{
						for(i=0;i<10&&stop==0;i++)
						{
							if(cptr->upper[i].booked==0)
							{
								cptr->upper[i].count=1;
								cptr->upper[i].id=ptr->id;
								cptr->upper[i].booked=1;
								stop=1;
								sc=SUCCESS;	
							}
						}
						if(sc==FAILURE)
						{
							for(i=0;i<10&&stop==0;i++)
							{
								if(cptr->lower[i].booked==0)
								{
									cptr->lower[i].count=1;
									cptr->lower[i].id=ptr->id;
									cptr->lower[i].booked=1;
									stop=1;
									sc=SUCCESS;	
								}
							}
							if(sc==FAILURE)
							{
								for(i=0;i<10&&stop==0;i++)
								{
									if(cptr->middle[i].booked==0)
									{
										cptr->middle[i].count=1;
										cptr->middle[i].id=ptr->id;
										cptr->middle[i].booked=1;
										stop=1;
										sc=SUCCESS;	
									}
								}
								if(sc==FAILURE)
								{
									for(i=0;i<5&&stop==0;i++)
									{
										if(cptr->side_upper[i].booked==0)
										{
											cptr->side_upper[i].count=1;
											cptr->side_upper[i].id=ptr->id;
											cptr->side_upper[i].booked=1;
											stop=1;
											sc=SUCCESS;	
										}
									}
								}								
							}							
						}						
					}					
				}
	//	 cptr=cptr->next;
	//	}while(cptr!=NULL&&stop==0)
	}
	else if(strcmp(ptr->preference,"side_upper")==0)
	{
		
		stop=0;
	//	do{
				for(i=0;i<5&&stop==0;i++)
				{
					if(cptr->side_upper[i].booked==0)
					{
						cptr->side_upper[i].count=1;
						cptr->side_upper[i].id=ptr->id;
						cptr->side_upper[i].booked=1;
					 stop=1;
					 sc=SUCCESS;	
					}
					
				}
				if(sc==FAILURE&&(ptr->age<15||ptr->age>60))
				{
					for(i=0;i<10&&stop==0;i++)
					{
						if(cptr->lower[i].booked==0)
						{
							cptr->lower[i].count=1;
							cptr->lower[i].id=ptr->id;
							cptr->lower[i].booked=1;
						 stop=1;
						 sc=SUCCESS;	
						}
					}
					if(sc==FAILURE)
					{
						for(i=0;i<10&&stop==0;i++)
						{
							if(cptr->upper[i].booked==0)
							{
								cptr->upper[i].count=1;
								cptr->upper[i].id=ptr->id;
								cptr->upper[i].booked=1;
								stop=1;
								sc=SUCCESS;	
							}
						}
						if(sc==FAILURE)
						{
							for(i=0;i<10&&stop==0;i++)
							{
								if(cptr->lower[i].booked==0)
								{
									cptr->lower[i].count=1;
									cptr->lower[i].id=ptr->id;
									cptr->lower[i].booked=1;
									stop=1;
									sc=SUCCESS;	
								}
							}
							if(sc==FAILURE)
							{
								for(i=0;i<10&&stop==0;i++)
								{
									if(cptr->middle[i].booked==0)
									{
										cptr->middle[i].count=1;
										cptr->middle[i].id=ptr->id;
										cptr->middle[i].booked=1;
										stop=1;
										sc=SUCCESS;	
									}
								}
								if(sc==FAILURE)
								{
									for(i=0;i<5&&stop==0;i++)
									{
										if(cptr->side_lower[i].booked==0)
										{
											cptr->side_lower[i].count=1;
											cptr->side_lower[i].id=ptr->id;
											cptr->side_lower[i].booked=1;
											stop=1;
											sc=SUCCESS;	
										}
									}
								}								
							}							
						}						
					}					
				}
	//	 cptr=cptr->next;
	//	}while(cptr!=NULL&&stop==0)
	}
 return sc;
}
void bookTricket(int ticket_id,passenger_type* plist,train_type* train_ptr,int train_count,int coach_id)
{
	
	
	int i,j,count;
	passenger_type *ptr,*newnode,*pass,*ptemp,*coach_passenger,*a;
	ptr=passengerlist(train_ptr,train_count,coach_id);
	train_type* tptr=train_ptr;
	coach_type* cptr;
		if(tptr!=NULL)
		{
			while(tptr!=NULL&&tptr->count!=train_count)
			{
				tptr=tptr->next;
			}
			if(tptr->coach_ptr==NULL)
			{
				printf("\n\t ---coach is not found");
			}
			else{	
					cptr=tptr->coach_ptr;
					while(cptr!=NULL&&cptr->count!=coach_id)
					{
						cptr=cptr->next;
					}
					if(cptr==NULL)
					{
						printf("\n\t ---coach number is not found");
					}
					 pass=plist;
					 while(pass!=NULL)
					 {
					 	
						 newnode=generatepassenger();
						newnode->age=pass->age;
						newnode->id=pass->id;
						strcpy(newnode->name,pass->name);
						strcpy(newnode->address,pass->address);
						strcpy(newnode->phone_no,pass->phone_no);
						strcpy(newnode->preference,pass->preference);
						i=perfectseat(cptr,newnode);					 	
					 	if(i==0)
					 	{
					 		ptemp=pass;
					 		a=cptr->rac_list;
					 		if(a==NULL)
					 		{
					 			count==0;
							 }
							 else
							 {
							 	while(a!=NULL&&count<=3)
							 	{
							 		count++;
							 		a=a->next;
								}
							 }
					 		if(count<2)
					 		{
					 			printf("\n %d is add--rac ",ptemp->id);
						 		cptr->rac_list=addpassenger(cptr->rac_list,ptemp);
							}
							else
							{
								printf("\n %d is add--waiting ",ptemp->id);
						 		cptr->waiting_list=addpassenger(cptr->waiting_list,ptemp);								
							}
						}
						else if(i==1)
						{
							coach_passenger=pass;
							cptr->passenger_ptr=addpassenger(cptr->passenger_ptr,coach_passenger);
						//	cptr->passenger_ptr=displayplist(cptr->passenger_ptr);
							
						}
						
						a=pass;
					 	pass=pass->next;
					 	free(a);
					 	plist=pass;
					 }
					 cptr->rac_list=displayplist(cptr->rac_list);
					
				}
		}
}
void cancelTicket(coach_type* cptr,int passenger_id)
{
	int i,stop=0,j,found=0;
	passenger_type *ptr,*plist;
	passenger_type *racplist=NULL,*temp,*all;	
	ptr=cptr->passenger_ptr;
	while(ptr!=NULL)
	{
		if(ptr->id==passenger_id)
		{
			found=1;
			cptr->passenger_ptr=deletepassenger(cptr->passenger_ptr,ptr);
		}
	 ptr=ptr->next;
	}
	if(found==1)
	{
	
		for(i=0;i<10&&stop==0;i++)
		{
			if(cptr->lower[i].booked==1)
			{
				for(j=0;j<cptr->lower[i].count;j++)
				{
					if(cptr->lower[i].id==passenger_id)
					{
						stop=1;
						cptr->lower[i].count--;
						if(cptr->lower[i].count==0)
						{
							if(cptr->rac_list!=NULL)
							{
								plist=cptr->passenger_ptr;
								while(plist->next!=NULL)
								{
									plist=plist->next;
								}
									cptr->lower[i].count++;
									cptr->lower[i].id=cptr->rac_list->id;				
									plist->next=cptr->rac_list;
									cptr->rac_list->prev=plist;
									cptr->rac_list=cptr->rac_list->next;
									(plist->next)->next=NULL;
									if(cptr->waiting_list!=NULL)
									{
										cptr->rac_list->next=cptr->waiting_list;
										cptr->waiting_list->prev=cptr->rac_list;
										(cptr->waiting_list)=(cptr->waiting_list)->next;
										temp=(cptr->rac_list)->next;
										all=temp->next;
					 		 	 		all->prev=NULL;
										temp->next=NULL;
									}
							}
							else
							{
							cptr->lower[i].booked=0;
							cptr->lower[i].id=0;
							}
						}
					}
				}
			}
		}
		for(i=0;i<10&&stop==0;i++)
		{
			if(cptr->upper[i].booked==1)
			{
				for(j=0;j<cptr->upper[i].count;j++)
				{
					if(cptr->upper[i].id==passenger_id)
					{
						stop=1;
						cptr->upper[i].count--;
						if(cptr->upper[i].count==0)
						{
							if(cptr->rac_list!=NULL)
							{
								plist=cptr->passenger_ptr;
								while(plist->next!=NULL)
								{
									plist=plist->next;
								}
									cptr->upper[i].count++;
									cptr->upper[i].id=cptr->rac_list->id;																
									plist->next=cptr->rac_list;
									cptr->rac_list->prev=plist;
									cptr->rac_list=cptr->rac_list->next;
									(plist->next)->next=NULL;
									if(cptr->waiting_list!=NULL)
									{
										cptr->rac_list->next=cptr->waiting_list;
										cptr->waiting_list->prev=cptr->rac_list;
										(cptr->waiting_list)=(cptr->waiting_list)->next;
										temp=(cptr->rac_list)->next;
										all=temp->next;
					 		 	 		all->prev=NULL;
										temp->next=NULL;
									}
							}
							else
							{							
							cptr->upper[i].booked=0;
							}
						}					
					}
				}
			}
		}
		for(i=0;i<10&&stop==0;i++)
		{
			if(cptr->middle[i].booked==1)
			{
				for(j=0;j<cptr->middle[i].count;j++)
				{
					if(cptr->middle[i].id==passenger_id)
					{
						stop=1;
						cptr->middle[i].count--;
						if(cptr->middle[i].count==0)
						{
							if(cptr->rac_list!=NULL)
							{
								plist=cptr->passenger_ptr;
								while(plist->next!=NULL)
								{
									plist=plist->next;
								}
									cptr->middle[i].count++;
									cptr->middle[i].id=cptr->rac_list->id;																
									plist->next=cptr->rac_list;
									cptr->rac_list->prev=plist;
									cptr->rac_list=cptr->rac_list->next;
									(plist->next)->next=NULL;
									if(cptr->waiting_list!=NULL)
									{
										cptr->rac_list->next=cptr->waiting_list;
										cptr->waiting_list->prev=cptr->rac_list;
										(cptr->waiting_list)=(cptr->waiting_list)->next;
										temp=(cptr->rac_list)->next;
										all=temp->next;
					 		 	 		all->prev=NULL;
										temp->next=NULL;
									}
							}
							else
							{							
							cptr->middle[i].booked=0;
							}
						}
					}
				}
			}
		}
		for(i=0;i<5&&stop==0;i++)
		{
			if(cptr->side_lower[i].booked==1)
			{
				for(j=0;j<cptr->side_lower[i].count;j++)
				{
					if(cptr->side_lower[i].id==passenger_id)
					{
						stop=1;
						cptr->side_lower[i].count--;
						if(cptr->side_lower[i].count==0)
						{
							if(cptr->rac_list!=NULL)
							{
								plist=cptr->passenger_ptr;
								while(plist->next!=NULL)
								{
									plist=plist->next;
								}
									cptr->side_lower[i].count++;
									cptr->side_upper[i].id=cptr->rac_list->id;																
									plist->next=cptr->rac_list;
									cptr->rac_list->prev=plist;
									cptr->rac_list=cptr->rac_list->next;
									(plist->next)->next=NULL;
									if(cptr->waiting_list!=NULL)
									{
										cptr->rac_list->next=cptr->waiting_list;
										cptr->waiting_list->prev=cptr->rac_list;
										(cptr->waiting_list)=(cptr->waiting_list)->next;
										temp=(cptr->rac_list)->next;
										all=temp->next;
					 		 	 		all->prev=NULL;
										temp->next=NULL;
									}
							}
							else
							{							
							cptr->side_lower[i].booked=0;
							}
						}
					}
				}
			}
		}
		for(i=0;i<5&&stop==0;i++)
		{
			if(cptr->side_upper[i].booked==1)
			{
				for(j=0;j<cptr->side_upper[i].count;j++)
				{
					if(cptr->side_upper[i].id==passenger_id)
					{
						stop=1;
						cptr->side_upper[i].count--;
						if(cptr->side_upper[i].count==0)
						{
							if(cptr->rac_list!=NULL)
							{
								plist=cptr->passenger_ptr;
								while(plist->next!=NULL)
								{
									plist=plist->next;
								}
									cptr->side_upper[i].count++;
									cptr->side_upper[i].id=cptr->rac_list->id;																
									plist->next=cptr->rac_list;
									cptr->rac_list->prev=plist;
									cptr->rac_list=cptr->rac_list->next;
									(plist->next)->next=NULL;
									if(cptr->waiting_list!=NULL)
									{
										cptr->rac_list->next=cptr->waiting_list;
										cptr->waiting_list->prev=cptr->rac_list;
										(cptr->waiting_list)=(cptr->waiting_list)->next;
										temp=(cptr->rac_list)->next;
										all=temp->next;
					 		 	 		all->prev=NULL;
										temp->next=NULL;
									}
							}
							else
							{							
							cptr->side_upper[i].booked=0;
							}
						}
					}
				}
			}
		}
	}
    else if(found==0)
    {
	
		ptr=cptr->rac_list;
		while(ptr!=NULL)
		{
			if(ptr->id==passenger_id)
			{
				found=1;
				cptr->rac_list=deletepassenger(cptr->rac_list,ptr);
				if(cptr->waiting_list!=NULL)
				{
					cptr->rac_list->next=cptr->waiting_list;
					cptr->waiting_list->prev=cptr->rac_list;
					(cptr->waiting_list)=(cptr->waiting_list)->next;
					temp=(cptr->rac_list)->next;
					all=temp->next;
 		 	 		all->prev=NULL;
					temp->next=NULL;
				}
			}
			 ptr=ptr->next;
		}
	}
	 if(found==0)
	{
		ptr=cptr->waiting_list;
		while(ptr!=NULL)
		{
			if(ptr->id==passenger_id)
			{
				found==0;
				cptr->waiting_list=deletepassenger(cptr->waiting_list,ptr);
			}
		 ptr=ptr->next;
		}
	}
	else 
	{
		printf("\n not forund\n");
	}

}
void freezeBooking(coach_type* cptr)
{
	int i,stop=0,full=0;
	passenger_type* racplist=NULL,*ptr,*temp,*all;
	racplist=cptr->rac_list;
	if(racplist!=NULL)
	{
		while(racplist!=NULL&&full==0)
		{
			stop=0;
			for(i=0;i<5&&stop==0;i++)
			{
				if(cptr->side_lower[i].count==1)
				{
					stop=1;
					cptr->side_lower[i].id2=racplist->id;
					cptr->side_lower[i].count++;
					
				}
			}
			if(stop==1){
				ptr=racplist;
				racplist=racplist->next;
			//	free(ptr);
				cptr->passenger_ptr=addpassenger(cptr->passenger_ptr,ptr);
				if(cptr->waiting_list!=NULL&&racplist!=NULL)
				{
				
					ptr=racplist;
					all=racplist;
					temp=cptr->waiting_list;
					ptr->next=temp;
					temp->prev=ptr;
					if(temp->next!=NULL)
					{
					
						temp=temp->next;
						ptr=ptr->next;
						ptr->next=NULL;
						temp->prev=NULL;
						cptr->rac_list=all;
						cptr->waiting_list=temp;
				    }
				    cptr->waiting_list=temp;
				    cptr->rac_list=all;
				}
			}
			else if(stop==0)
				{
			
				racplist=racplist->next;
					if(cptr->waiting_list==NULL)
					{
					
					full=1;
					}
				}
			else
			{
				racplist=racplist->next;
			}
		}
	}
	
}
int main()
{
		int id,age;
	char name[50],address[50],phone[50],pref[50];
	int i,flag=1,j,k,inc=70,ie;
	 train_type* train_ptr=NULL;
	 passenger_type* plist=NULL,*pass=NULL;
	 coach_type* cptr=NULL;
	 char c[22];
	  FILE *fp;
	  
	  
	  
	 train_ptr=addTrain(train_ptr);
	 train_ptr=addTrain(train_ptr);
	 train_ptr=addTrain(train_ptr);
//	 train_ptr=displaytrain(train_ptr);
	 i=addCouch(train_ptr,01);
	 i=addCouch(train_ptr,01);
	 i=addCouch(train_ptr,02);
	 i=addCouch(train_ptr,02);
//	displayCouchdata(train_ptr,1,1);
	 printf("\n\n\n");
//	 displayCouchdata(train_ptr,1,2);
	
	
	
   fp = fopen("file.txt","r");
   if(fp!=NULL)
   {
	   while(!feof(fp)) 
	   {
	   	pass==NULL;
	   		 pass=generatepassenger();
	      fscanf(fp,"%d)%s %s %s %s %d\n",&id,name,address,phone,pref,&age);
	      	 pass->id=id;
	      	 strcpy(pass->name,name);
		 strcpy(pass->address,address);
		 strcpy(pass->phone_no,phone);
		 pass->age=age;
		 strcpy(pass->preference,pref);
		 plist=addpassenger(plist,pass);
		}
		 //plist=displayplist(plist);
		 
		bookTricket(01,plist,train_ptr,1,1);	 	 	
	 	displayCouchdata(train_ptr,1,1);
	}
	else
	{
		printf("\n error :-file is not fopen due to os ");
	}
	 	printf("\nassumption all work is done on train no 1,coach no 1\n");
	 	 cptr=getarequiredcoachformtrain(train_ptr,1,1);
		while(flag==1)
		{
				
			printf("\n------------------------------\n");
			printf("1) for add a coach\n2)book a ticket\n3)cancleTicket\n4)display the coach data\n5)Freeze\n");
			scanf("%d",&j);
				switch(j)
				{
					case 1:
							 printf("\n enter train no\n");
							 scanf("%d",&i);
							 k=addCouch(train_ptr,i);
							 if(k==1)
							 {
							 	printf("\n coach added successfully\n");
							 }
							 else
							 {
							 	printf("\nerror: coach not addded");
	
							 }
					break;
					case 2:
								printf("\nassumption all work is done on train no 1,coach no 1\n");
														 	
						 		plist=NULL;
						 		 cptr=getarequiredcoachformtrain(train_ptr,1,1);
						 		 printf("\nenter how many passenger you want to add in coach\n");
						 		 scanf("%d",&i);
						 		 for(j=0;j<i;j++)
						 		 {
						 			 pass=generatepassenger();
						 		 	 printf("\nenter the name\n");
						 		 	 scanf("%s",pass->name);
						 		 	 pass->id=inc++;
						 		 	 printf("\nenter the addres\n");
						 		 	 scanf("%s",pass->address);
						 		 	 printf("\nenter the phone no\n");
						 		 	 scanf("%s",pass->phone_no);
						 		 	 printf("\nenter  Age\n");
						 		 	 scanf("%d",&pass->age);
						 		 	 printf("\nselect prefernce:-\n1)lower\n2)middle\n3)upper\n4)side_lower\n5)side_upper\n");
						 		 	 scanf("%d",&k);
						 		 	 	switch(k)
						 		 	 	{
						 		 	 		case 1:
						 		 	 			strcpy(pass->preference,"lower");
						 		 	 			break;
						 		 	 		case 2:
						 		 	 			strcpy(pass->preference,"middle");
						 		 	 			break;
						 		 	 		case 3:
						 		 	 			strcpy(pass->preference,"upper");
						 		 	 			break;
						 		 	 		case 4:
						 		 	 			strcpy(pass->preference,"side_lower");
						 		 	 			break;
						 		 	 		case 5:
						 		 	 			strcpy(pass->preference,"side_upper");
						 		 	 			break;
						 		 	 		default :
						 		 	 			printf("\n enter the corect value\n");
						 		 	 			break;
										}
										plist=addpassenger(plist,pass);
								 }

									  
	  	fp=fopen("file.txt", "a");
	  pass=plist;
	  while(pass!=NULL)
	  {
	  fprintf(fp, "%d)%s %s %s %s %d\n", pass->id,pass->name,pass->address,pass->phone_no,pass->preference,pass->age);
	  pass=pass->next; 
	  }
	  
	  fclose(fp);


								 	 	bookTricket(01,plist,train_ptr,1,1);
	 									displayCouchdata(train_ptr,1,1);
									printf("\n======================RAC list is \n");
							 		 	 cptr->rac_list=displayplist(cptr->rac_list);
										   printf("\n****************** WAITING list is \n");								  						
									 cptr->waiting_list=displayplist(cptr->waiting_list);
									  printf("\n################# \n");

									  	 	 									
					break;
					case 3:
								printf("\nassumption all work is done on train no 1,coach no 1\n");
								printf("\nenter the data you want to delete \n");\
								scanf("%d",&ie);
						 		 cptr=getarequiredcoachformtrain(train_ptr,1,1);
							 		 cancelTicket(cptr,ie);
									displayCouchdata(train_ptr,1,1);
									printf("\n======================RAC list is \n");
							 		 	 cptr->rac_list=displayplist(cptr->rac_list);
										   printf("\n****************** WAITING list is \n");								  						
									 cptr->waiting_list=displayplist(cptr->waiting_list);
									  printf("\n################# \n");	 
	  	fp=fopen("file.txt", "w");
	  pass=cptr->passenger_ptr;
	  while(pass!=NULL)
	  {
	  fprintf(fp, "%d)%s %s %s %s %d\n", pass->id,pass->name,pass->address,pass->phone_no,pass->preference,pass->age);
	  pass=pass->next; 
	  }
	  fclose(fp);
	  									  
	  								  
					break;
					case 4:
								printf("\nassumption all work is done on train no 1,coach no 1\n");
						 		 cptr=getarequiredcoachformtrain(train_ptr,1,1);
									displayCouchdata(train_ptr,1,1);
					break;
					case 5:
							flag=0;
							printf("\n ---------------------------------initially \n");
								//	displayCouchdata(train_ptr,1,1);
									printf("\n======================RAC list is \n");
							 		 	 cptr->rac_list=displayplist(cptr->rac_list);
										   printf("\n****************** WAITING list is \n");								  						
									 cptr->waiting_list=displayplist(cptr->waiting_list);
									  printf("\n################# \n");
							printf("\n ---------------------------------finally \n");
								 	 freezeBooking(cptr);
								 	displayCouchdata(train_ptr,1,1);
									printf("\n======================RAC list is \n");
							 		 	 cptr->rac_list=displayplist(cptr->rac_list);
										   printf("\n****************** WAITING list is \n");								  						
									 cptr->waiting_list=displayplist(cptr->waiting_list);
									  printf("\n################# \n");									 			  
					break;
					default :
						flag=0;
					break;
				};
		}
		
				
	  fp=fp = fopen("pass_data.txt", "w");
	  pass=cptr->passenger_ptr;
	  while(pass!=NULL)
	  {
	  fprintf(fp,"\n%d)%s %s %s %s %d", pass->id,pass->name,pass->address,pass->phone_no,pass->preference,pass->age);
	  pass=pass->next;
	  }
	  fclose(fp);
	  
	  	  fp=fopen("rac_data.txt", "w");
	  pass=cptr->rac_list;
	  while(pass!=NULL)
	  {
	  fprintf(fp, "%d)%s %s %s %s %d\n", pass->id,pass->name,pass->address,pass->phone_no,pass->preference,pass->age);
	  pass=pass->next;
	  }
	  fclose(fp);
	  
	  	fp=fopen("waiting_data.txt", "w");
	  pass=cptr->waiting_list;
	  while(pass!=NULL)
	  {
	  fprintf(fp, "%d)%s %s %s %s %d\n", pass->id,pass->name,pass->address,pass->phone_no,pass->preference,pass->age);
	  pass=pass->next; 
	  }
	  
	  fclose(fp);
	  
	 return 0; 
}
