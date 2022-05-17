#include "header.h"
int * checking_arguments_R(char * buf,boolean * ERROR_FLAG,unsigned long * COUNTER_LINES, int end_index_dot_op, int inst_op){
int * OPERATORS_TABLE;
int index=0;
int digit_start;
int digit_end;
boolean DIGIT=F;
boolean COMMA=F;
boolean DOLLAR=F;
int operands_counter=0;
char * number;
int digit_size;
int num_of_operands;
int p;
int i;

	if(end_index_dot_op+1>=strlen(buf)){
		*ERROR_FLAG=T;
		printf("expect argumets\nLINE NUMBER:%lu",(*COUNTER_LINES));
		return NULL;}
		

	if(buf[end_index_dot_op+1]!=' ' && buf[end_index_dot_op+1]!='\t'){
		*ERROR_FLAG=T;
		printf("space or tab expected \nLINE NUMBER:%lu",(*COUNTER_LINES));
		return NULL;}

end_index_dot_op++;



	if(inst_op>=0 && inst_op<=4)
	num_of_operands=3;
	else
	num_of_operands=2;




OPERATORS_TABLE=(int *)calloc(num_of_operands,sizeof(int));

			if(!OPERATORS_TABLE){
				*ERROR_FLAG=T;
		printf("cannot allocated memmory\nLINE NUMBER:%lu",(*COUNTER_LINES));
				return NULL;}


			








for(index=end_index_dot_op;index<strlen(buf) && buf[index]!='\n';index++){





	if(DOLLAR==T && DIGIT==T && COMMA==T){


			
		if(operands_counter>=num_of_operands){
	printf("two manny oparands\nLINE NUMBER:%lu",(*COUNTER_LINES));
				*ERROR_FLAG=T;
				return NULL;}


		digit_size=digit_end-digit_start+2;
		number=(char *)calloc(digit_size,sizeof(char));

				if(!number){
				*ERROR_FLAG=T;
		printf("cannot allocated memmory\nLINE NUMBER:%lu",(*COUNTER_LINES));
				return NULL;}

		number[digit_size-1]='\0';
	
		for(i=0;i<digit_size-1;i++)
		number[i]=buf[digit_start++];

		
			
		OPERATORS_TABLE[operands_counter]=atoi(number);
			

		operands_counter++;
		DOLLAR=F;
		DIGIT=F;
		COMMA=F;
		
	
		}

	


	if(buf[index]==' ' || buf[index]=='\t')
	continue;

	

	
		if(buf[index]=='$'){


			if(DOLLAR==T){
	printf("2 Dollars apeard without digit and comma\nLINE NUMBER:%lu",(*COUNTER_LINES));
			*ERROR_FLAG=T;
			return NULL;}

		DOLLAR=T;
		continue;
		}

		

		if(isdigit(buf[index])!=0){
			
			if(DIGIT==T){
		printf("COMMA EXPECTED\nLINE NUMBER:%lu",(*COUNTER_LINES));
			*ERROR_FLAG=T;
			return NULL;}

			if(DOLLAR==F){
		printf("DOLLAR COME BEFORE DIGIT\nLINE NUMBER:%lu",(*COUNTER_LINES));
			*ERROR_FLAG=T;
			return NULL;}

		digit_start=index;
		digit_end=index;
			while(index+1<strlen(buf)&&isdigit(buf[index+1])!=0)
			index++;
		digit_end=index;
		DIGIT=T;
		continue;
		}


		if(buf[index]==','){
		
			if(COMMA==T){
printf("2 comma's apeard without opeerans between them \nLINE NUMBER:%lu",(*COUNTER_LINES));
			*ERROR_FLAG=T;
			return NULL;}

			if(DOLLAR==F|| DIGIT==F){
	printf("DOLLAR and DIGIT come before comma\nLINE NUMBER:%lu",(*COUNTER_LINES));
			*ERROR_FLAG=T;
			return NULL;}

		COMMA=T;
		continue;}





 
printf("%d   %c  expect dollar or comma or digit\nLINE NUMBER:%lu",strlen(buf),buf[index],(*COUNTER_LINES));
			*ERROR_FLAG=T;
			return NULL;

		}


if(DOLLAR==T && DIGIT==T && operands_counter==num_of_operands-1){


		digit_size=digit_end-digit_start+2;
		number=(char *)calloc(digit_size,sizeof(char));

				if(!number){
				*ERROR_FLAG=T;
		printf("cannot allocated memmory\nLINE NUMBER:%lu",(*COUNTER_LINES));
				return NULL;}

		number[digit_size-1]='\0';
	
		for(i=0;i<digit_size-1;i++)
		number[i]=buf[digit_start++];

		
			
		OPERATORS_TABLE[operands_counter]=atoi(number);
			
	
		operands_counter++;
		
	
		}



if(operands_counter==num_of_operands){
	for(p=0;p<operands_counter;p++){
		if(OPERATORS_TABLE[p]>31 || OPERATORS_TABLE[p]<0){
		
printf("accumulator number incorrect\nLINE NUMBER:%lu",(*COUNTER_LINES));
				*ERROR_FLAG=T;
				return NULL;
				}
			}

	return OPERATORS_TABLE;
		}



		
	printf("you didnt enterd inuff operands\nLINE NUMBER:%lu",(*COUNTER_LINES));
			*ERROR_FLAG=T;
			return NULL;

}









int * I_coditional(char * buf, boolean * ERROR_FLAG, unsigned long * COUNTER_LINES, int end_index_dot_op, int inst_op,char * label_operator){

int * OPERATORS_TABLE;
char * number=NULL;
int p,i;
int operands_counter=0;
int label_counter=0;
int index=0;
int start_label=0;
int end_label=0;
int label_size=0;
int digit_start=0;
int digit_end=0;
int digit_size=0;
boolean STRING=F;
boolean DOLLAR=F;
boolean DIGIT=F;
boolean COMMA=F;


if(end_index_dot_op+1>=strlen(buf)){
		*ERROR_FLAG=T;
		printf("expect argumets\nLINE NUMBER:%lu",(*COUNTER_LINES));
		return NULL;}


	if(buf[end_index_dot_op+1]!=' ' && buf[end_index_dot_op+1]!='\t'){
		*ERROR_FLAG=T;
		printf("space or tab expected \nLINE NUMBER:%lu",(*COUNTER_LINES));
		return NULL;}

end_index_dot_op++;


	OPERATORS_TABLE=(int *)calloc(2,sizeof(int));

		if (!OPERATORS_TABLE){
	printf("cannot allocate memory\nLINE NUMBER:%lu",(*COUNTER_LINES));
				*ERROR_FLAG=T;
				return NULL;}



for(index=end_index_dot_op;index<strlen(buf) && buf[index]!='\n';index++){


	
	if(DOLLAR==T && DIGIT==T && COMMA==T ){
		
		
	if(operands_counter>=2){
	printf("two manny oparands\nLINE NUMBER:%lu",(*COUNTER_LINES));
				*ERROR_FLAG=T;
				return NULL;}
	
		
			
			

		digit_size=digit_end-digit_start+2;
		number=(char *)calloc(digit_size,sizeof(char));
				if (!number){
	printf("cannot allocate memory\nLINE NUMBER:%lu",(*COUNTER_LINES));
				*ERROR_FLAG=T;
				return NULL;}


		number[digit_size-1]='\0';
	
		for(i=0;i<digit_size-1;i++)
		number[i]=buf[digit_start++];

		
			
		OPERATORS_TABLE[operands_counter]=atoi(number);
		free(number);
		DIGIT=F;
		COMMA=F;
		STRING=F;
		DOLLAR=F;
		operands_counter++;


			}


	
	if(STRING==T && COMMA==T){
	
		
if(label_counter>=1){
	printf("two manny oparands\nLINE NUMBER:%lu",(*COUNTER_LINES));
				*ERROR_FLAG=T;
				return NULL;}
	


	label_size=end_label-start_label+2;


	

		
				

		label_operator[label_size-1]='\0';
	
		for(i=0;i<label_size-1;i++)
		label_operator[i]=buf[start_label++];

			
	DIGIT=F;
	COMMA=F;		
	STRING=F;
	label_counter++;

	}

	
	



	if(buf[index]==' ' || buf[index]=='\t')
	continue;

	

	
		if(buf[index]=='$'){


			if(DOLLAR==T){
	printf("2 Dollars apeard without digit and comma\nLINE NUMBER:%lu",(*COUNTER_LINES));
			*ERROR_FLAG=T;
			return NULL;}
			
		

		DOLLAR=T;
		continue;
		}

		

		if(isdigit(buf[index])!=0){
		
				if(DOLLAR==F){
		printf("DOLLAR EXPECTED\nLINE NUMBER:%lu",(*COUNTER_LINES));
				*ERROR_FLAG=T;
				return NULL;}
			
				if(DIGIT==T){
		printf("SYNTAX ERROR\nLINE NUMBER:%lu",(*COUNTER_LINES));
				*ERROR_FLAG=T;
				return NULL;}
	
				if(STRING==T){
		printf("SYNTAX ERROR\nLINE NUMBER:%lu",(*COUNTER_LINES));
				*ERROR_FLAG=T;
				return NULL;}


		digit_start=index;
		digit_end=index;
			while(index+1<LINE_SIZE-1&&isdigit(buf[index+1])!=0)
			index++;
		digit_end=index;
		DIGIT=T;
		continue;
		}


	



		if(isalpha(buf[index])!=0){

				if(DIGIT==T){
		printf("SYNTAX ERROR\nLINE NUMBER:%lu",(*COUNTER_LINES));
				*ERROR_FLAG=T;
				return NULL;}
	
				if(STRING==T){
		printf("SYNTAX ERROR\nLINE NUMBER:%lu",(*COUNTER_LINES));
				*ERROR_FLAG=T;
				return NULL;}
		start_label=index;
		end_label=index;
 while(index+1<LINE_SIZE-1 &&(isalpha(buf[index+1])!=0||isdigit(buf[index])!=0))
			index++;
		end_label=index;
		STRING=T;
		continue;
		
			}



		if(buf[index]==','){
		
			if(COMMA==T){
printf("2 comma's apeard without opeerans between them \nLINE NUMBER:%lu",(*COUNTER_LINES));
			*ERROR_FLAG=T;
			return NULL;}

			if(DIGIT==F && STRING==F){
	printf(" DIGIT OR STRING come before comma\nLINE NUMBER:%lu",(*COUNTER_LINES));
			*ERROR_FLAG=T;
			return NULL;}



			

		COMMA=T;
		continue;}





	
printf("COMMA,SPACE,TAB,DIGIT,DOLLAR EXPECTED\nLINE NUMBER:%lu",(*COUNTER_LINES));
				*ERROR_FLAG=T;
				return NULL;

		}







if(DOLLAR==T && DIGIT==T ){
		
		
	
	
		
			

		digit_size=digit_end-digit_start+2;
		number=(char *)calloc(digit_size,sizeof(char));
				if (!number){
	printf("cannot allocate memory\nLINE NUMBER:%lu",(*COUNTER_LINES));
				*ERROR_FLAG=T;
				return NULL;}


		number[digit_size-1]='\0';
	
		for(i=0;i<digit_size-1;i++)
		number[i]=buf[digit_start++];

		
			
		OPERATORS_TABLE[operands_counter]=atoi(number);
		operands_counter++;
		free(number);
		





	}

	
	if(STRING==T){
	
		



	label_size=end_label-start_label+2;



		
				

		label_operator[label_size-1]='\0';
	
		for(i=0;i<label_size-1;i++)
		label_operator[i]=buf[start_label++];

			
		label_counter++;



	}

if(label_counter==1 & operands_counter==2){
	for(p=0;p<2;p++){


		if(OPERATORS_TABLE[p]>31 || OPERATORS_TABLE[p]<0){
printf("accumulator number incorrect\nLINE NUMBER:%lu",(*COUNTER_LINES));
				*ERROR_FLAG=T;
				return NULL;
				}
			}

	return OPERATORS_TABLE;
		}



return NULL;


	}



int * checking_arguments_I_aritmathic(char * buf,boolean * ERROR_FLAG,unsigned long * COUNTER_LINES, int end_index_dot_op, int inst_op){
int * OPERATORS_TABLE;
int index=0;
int digit_start;
int digit_end;
boolean DIGIT=F;
boolean COMMA=F;
boolean DOLLAR=F;
boolean SIGN=F;
int reg_counter=0;
int immed_counter=0;
char * number;
int digit_size;
int num_of_operands=3;
int p;
int i;

	if(end_index_dot_op+1>=strlen(buf)){
		*ERROR_FLAG=T;
		printf("expect argumets\nLINE NUMBER:%lu",(*COUNTER_LINES));
		return NULL;}
		

	if(buf[end_index_dot_op+1]!=' ' && buf[end_index_dot_op+1]!='\t'){
		*ERROR_FLAG=T;
		printf("space or tab expected \nLINE NUMBER:%lu",(*COUNTER_LINES));
		return NULL;}

end_index_dot_op++;




OPERATORS_TABLE=(int *)calloc(num_of_operands,sizeof(int));

			if(!OPERATORS_TABLE){
				*ERROR_FLAG=T;
		printf("cannot allocated memmory\nLINE NUMBER:%lu",(*COUNTER_LINES));
				return NULL;}


			








for(index=end_index_dot_op;index<strlen(buf) && buf[index]!='\n';index++){





	if(DOLLAR==T && DIGIT==T && COMMA==T){


			
		if(reg_counter>=2){
	printf("two manny oparands\nLINE NUMBER:%lu",(*COUNTER_LINES));
				*ERROR_FLAG=T;
				return NULL;}


		digit_size=digit_end-digit_start+2;
		number=(char *)calloc(digit_size,sizeof(char));

				if(!number){
				*ERROR_FLAG=T;
		printf("cannot allocated memmory\nLINE NUMBER:%lu",(*COUNTER_LINES));
				return NULL;}

		
	
		for(i=0;i<digit_size-1;i++)
		number[i]=buf[digit_start++];
		number[i]='\0';

		
			
		OPERATORS_TABLE[reg_counter]=atoi(number);
			
	
		reg_counter++;
		DOLLAR=F;
		DIGIT=F;
		COMMA=F;
			}





		if(DIGIT==T && COMMA==T){


	
		if(immed_counter>=1){
	printf("two manny oparands\nLINE NUMBER:%lu",(*COUNTER_LINES));
				*ERROR_FLAG=T;
				return NULL;}


		digit_size=digit_end-digit_start+2;
		number=(char *)calloc(digit_size,sizeof(char));

				if(!number){
				*ERROR_FLAG=T;
		printf("cannot allocated memmory\nLINE NUMBER:%lu",(*COUNTER_LINES));
				return NULL;}

		
	
		for(i=0;i<digit_size-1;i++)
		number[i]=buf[digit_start++];
		number[i]='\0';

		if(SIGN==T)
			
		OPERATORS_TABLE[2]=-atoi(number);
			
			else
			
			OPERATORS_TABLE[2]=atoi(number);
		
		
		immed_counter++;
		SIGN=F;
		DIGIT=F;
		COMMA=F;
		
	
		}

	


	if(buf[index]==' ' || buf[index]=='\t')
	continue;

	

	
		if(buf[index]=='$'){


			if(DOLLAR==T){
	printf("2 Dollars apeard without digit and comma\nLINE NUMBER:%lu",(*COUNTER_LINES));
			*ERROR_FLAG=T;
			return NULL;}

		DOLLAR=T;
		continue;
		}


		
		if(buf[index]=='-'){
		SIGN=T;
		continue;
		}


		if(buf[index]=='+')
		continue;
		
		

		if(isdigit(buf[index])!=0){
			
			if(DIGIT==T){
		printf("COMMA EXPECTED\nLINE NUMBER:%lu",(*COUNTER_LINES));
			*ERROR_FLAG=T;
			return NULL;}


		digit_start=index;
		digit_end=index;
			while(index+1<strlen(buf)&&isdigit(buf[index+1])!=0)
			index++;
		digit_end=index;
		DIGIT=T;
		continue;
		}






		if(buf[index]==','){
		
			if(COMMA==T){
printf("2 comma's apeard without opeerans between them \nLINE NUMBER:%lu",(*COUNTER_LINES));
			*ERROR_FLAG=T;
			return NULL;}

			if(DIGIT==F){
	printf(" DIGIT come before comma\nLINE NUMBER:%lu",(*COUNTER_LINES));
			*ERROR_FLAG=T;
			return NULL;}

		COMMA=T;
		continue;}





 
printf("expect dollar or comma or digit\nLINE NUMBER:%lu",(*COUNTER_LINES));
			*ERROR_FLAG=T;
			return NULL;

		}


if(DOLLAR==T && DIGIT==T){


		digit_size=digit_end-digit_start+2;
		number=(char *)calloc(digit_size,sizeof(char));

				if(!number){
				*ERROR_FLAG=T;
		printf("cannot allocated memmory\nLINE NUMBER:%lu",(*COUNTER_LINES));
				return NULL;}

		number[digit_size-1]='\0';
	
		for(i=0;i<digit_size-1;i++)
		number[i]=buf[digit_start++];

		
			
		OPERATORS_TABLE[reg_counter]=atoi(number);
			
	
		reg_counter++;
		DOLLAR=F;
		DIGIT=F;
	
		}




if(DIGIT==T){


		digit_size=digit_end-digit_start+2;
		number=(char *)calloc(digit_size,sizeof(char));

				if(!number){
				*ERROR_FLAG=T;
		printf("cannot allocated memmory\nLINE NUMBER:%lu",(*COUNTER_LINES));
				return NULL;}

		number[digit_size-1]='\0';
	
		for(i=0;i<digit_size-1;i++)
		number[i]=buf[digit_start++];

		if(SIGN==T)
			
		OPERATORS_TABLE[2]=-(atoi(number));
			
			else
			
			OPERATORS_TABLE[2]=atoi(number);
			
		
			
	
		immed_counter++;
		
	
		}



if(immed_counter==1 & reg_counter==2){
	for(p=0;p<2;p++){


		if(OPERATORS_TABLE[p]>31 || OPERATORS_TABLE[p]<0){
printf("accumulator number incorrect\nLINE NUMBER:%lu",(*COUNTER_LINES));
				*ERROR_FLAG=T;
				return NULL;
				}
			}

	return OPERATORS_TABLE;
		}



		
	printf("you didnt enterd inuff operands\nLINE NUMBER:%lu",(*COUNTER_LINES));
			*ERROR_FLAG=T;
			return NULL;

}










int * checking_arguments_jmp(char * buf, boolean * ERROR_FLAG, unsigned long * COUNTER_LINES, int end_index_dot_op, int inst_op,char * label_operator,int * OPERATORS_TABLE){


char * number=NULL;
int p,i;
int operands_counter=0;
int label_counter=0;
int index=0;
int start_label=0;
int end_label=0;
int label_size=0;
int digit_start=0;
int digit_end=0;
int digit_size=0;
boolean STRING=F;
boolean DOLLAR=F;
boolean DIGIT=F;


if(end_index_dot_op+1>=strlen(buf)){
		*ERROR_FLAG=T;
		printf("expect argumets\nLINE NUMBER:%lu",(*COUNTER_LINES));
		return NULL;}


	if(buf[end_index_dot_op+1]!=' ' && buf[end_index_dot_op+1]!='\t'){
		*ERROR_FLAG=T;
		printf("space or tab expected \nLINE NUMBER:%lu",(*COUNTER_LINES));
		return NULL;}

end_index_dot_op++;


	
		



for(index=end_index_dot_op;index<strlen(buf) && buf[index]!='\n';index++){

	
	



	if(buf[index]==' ' || buf[index]=='\t')
	continue;

	

	
		if(buf[index]=='$'){


			if(DOLLAR==T){
	printf("2 Dollars apeard without digit and comma\nLINE NUMBER:%lu",(*COUNTER_LINES));
			*ERROR_FLAG=T;
			return NULL;}
			
		

		DOLLAR=T;
		continue;
		}

		

		if(isdigit(buf[index])!=0){
		
				if(DOLLAR==F){
		printf("DOLLAR EXPECTED\nLINE NUMBER:%lu",(*COUNTER_LINES));
				*ERROR_FLAG=T;
				return NULL;}
			
				if(DIGIT==T){
		printf("SYNTAX ERROR\nLINE NUMBER:%lu",(*COUNTER_LINES));
				*ERROR_FLAG=T;
				return NULL;}
	
				if(STRING==T){
		printf("SYNTAX ERROR\nLINE NUMBER:%lu",(*COUNTER_LINES));
				*ERROR_FLAG=T;
				return NULL;}


		digit_start=index;
		digit_end=index;
			while(index+1<LINE_SIZE-1&&isdigit(buf[index+1])!=0)
			index++;
		digit_end=index;
		DIGIT=T;
		continue;
		}


	



		if(isalpha(buf[index])!=0){

				if(DIGIT==T){
		printf("SYNTAX ERROR\nLINE NUMBER:%lu",(*COUNTER_LINES));
				*ERROR_FLAG=T;
				return NULL;}
	
				if(STRING==T){
		printf("SYNTAX ERROR\nLINE NUMBER:%lu",(*COUNTER_LINES));
				*ERROR_FLAG=T;
				return NULL;}
		start_label=index;
		end_label=index;
 while(index+1<LINE_SIZE-1 &&(isalpha(buf[index+1])!=0||isdigit(buf[index])!=0))
			index++;
		end_label=index;
		STRING=T;
		continue;
		
			}





	
printf("COMMA,SPACE,TAB,DIGIT,DOLLAR EXPECTED\nLINE NUMBER:%lu",(*COUNTER_LINES));
				*ERROR_FLAG=T;
				return NULL;

		}







if(DOLLAR==T && DIGIT==T ){
		
		
	
	
		OPERATORS_TABLE=(int *)calloc(2,sizeof(int));
			if (!OPERATORS_TABLE){
	printf("cannot allocate memory\nLINE NUMBER:%lu",(*COUNTER_LINES));
				*ERROR_FLAG=T;
				return NULL;}
			

		digit_size=digit_end-digit_start+2;
		number=(char *)calloc(digit_size,sizeof(char));
				if (!number){
	printf("cannot allocate memory\nLINE NUMBER:%lu",(*COUNTER_LINES));
				*ERROR_FLAG=T;
				return NULL;}


		number[digit_size-1]='\0';
	
		for(i=0;i<digit_size-1;i++)
		number[i]=buf[digit_start++];

		
			
		OPERATORS_TABLE[1]=atoi(number);
		OPERATORS_TABLE[0]=1;
		free(number);
		



	for(p=1;p<2;p++){
	if(OPERATORS_TABLE[p]>32 || OPERATORS_TABLE[p]<0){
		
printf("accumulator number incorrect\nLINE NUMBER:%lu",(*COUNTER_LINES));
				*ERROR_FLAG=T;
				return NULL;}
			}


return OPERATORS_TABLE;




	}

	
	if(STRING==T){
	
		

	OPERATORS_TABLE=(int *)calloc(1,sizeof(int));
				if (!OPERATORS_TABLE){
	printf("cannot allocate memory\nLINE NUMBER:%lu",(*COUNTER_LINES));
				*ERROR_FLAG=T;
				return NULL;}
	


	label_size=end_label-start_label+2;


	

		
				

		label_operator[label_size-1]='\0';
	
		for(i=0;i<label_size-1;i++)
		label_operator[i]=buf[start_label++];

			
		OPERATORS_TABLE[0]=0;
			

return OPERATORS_TABLE;

	}

return NULL;


	}







int checking_arguments_la_and_call(char * buf,boolean * ERROR_FLAG,unsigned long * COUNTER_LINES, int end_index_dot_op,char * label_operator)
{




int i=0;
boolean SPACE=F;
int index=0;
int start_label=0;
int end_label=0;
int label_size=0;
boolean STRING=F;
int operands_counter=0;

	if(end_index_dot_op+1>=strlen(buf)){
		*ERROR_FLAG=T;
		printf("expect argumets\nLINE NUMBER:%lu",(*COUNTER_LINES));
		return DEFAULT;}


	if(buf[end_index_dot_op+1]!=' ' && buf[end_index_dot_op+1]!='\t'){
		*ERROR_FLAG=T;
		printf("space or tab expected \nLINE NUMBER:%lu",(*COUNTER_LINES));
		return DEFAULT;}

end_index_dot_op++;


	
		



for(index=end_index_dot_op;index<strlen(buf) && buf[index]!='\n';index++){

	

	if(buf[index]==' ' || buf[index]=='\t'){
	if(STRING==T)
	SPACE=T;
	continue;}



	

		if(isalpha(buf[index])!=0){


				if(SPACE==T){
				*ERROR_FLAG=T;
		printf("YOU CANT DEFINE SYMBOL NAME WITH SPACES \nLINE NUMBER:%lu",(*COUNTER_LINES));
				return DEFAULT;}
				
		start_label=index;
		end_label=index;
 while(index+1<strlen(buf) &&(isalpha(buf[index+1])!=0||isdigit(buf[index])!=0))
			index++;
		end_label=index;
		STRING=T;
		continue;
		
			}

	
printf("SPACE,TAB,ALPHA EXPECTED HERE \nLINE NUMBER:%lu",(*COUNTER_LINES));
				*ERROR_FLAG=T;
				return DEFAULT;

		}




if(STRING==T){
	
		

	
	if(end_label-start_label>=LABEL_MAX_SIZE-1){
	printf("label limited to 31 char's\nLINE NUMBER:%lu",(*COUNTER_LINES));
			*ERROR_FLAG=T;
			return DEFAULT;}



	label_size=end_label-start_label;

		
	
		for(i=0;i<=label_size;i++)
		label_operator[i]=buf[start_label++];
		
		return SUCCESSFUL;

	}







printf("you didnt enterd inuff operands  \nLINE NUMBER:%lu",(*COUNTER_LINES));
			*ERROR_FLAG=T;
			return DEFAULT;
			


}


