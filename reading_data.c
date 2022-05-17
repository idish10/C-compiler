#include "header.h"
char * reading_data_asciz(char * buf, boolean * ERROR_FLAG,unsigned long * COUNTER_LINES, int end_index_dot_op, int inst_op,unsigned int * counter_numbers){

int asciz_size,i,start_index,end_index,index;
char * asciz=NULL;

if(end_index_dot_op+1>=strlen(buf)){
	printf("expcted READING DATA\n LINE NUMBER: %lu",(*COUNTER_LINES));
	*ERROR_FLAG=T;
	return NULL;}

		
	
	if(buf[end_index_dot_op+1]!=' '&& buf[end_index_dot_op+1]!='\t'){
printf("expcted space or tab between data and the name of method\n LINE NUMBER: %lu",(*COUNTER_LINES));
	*ERROR_FLAG=T;
	return NULL;}




end_index_dot_op++;


for(index=end_index_dot_op;index<strlen(buf) && buf[index]!='\n';index++){

	if(buf[index]==' ' || buf[index]=='\t')
		continue;



	if(buf[index]=='\"'){

		if(index+1>=strlen(buf)){
	printf("expcted READING DATA\n LINE NUMBER: %lu",(*COUNTER_LINES));
	*ERROR_FLAG=T;
	return NULL;}
		
		index++;
		start_index=index;
		end_index=index;

	while(index+1<strlen(buf) && buf[index+1]!='\n' && buf[index+1]!='\"')
			index++;
			end_index=index;

	if(index+1>=strlen(buf) || buf[index+1]!='\"'){
		printf("expcted closing quote\n LINE NUMBER: %lu",(*COUNTER_LINES));
		*ERROR_FLAG=T;
		return NULL;}

		index++;
		continue;}



printf("syntax error\n LINE NUMBER: %lu",(*COUNTER_LINES));
		*ERROR_FLAG=T;
		return NULL;
	}

asciz_size=end_index-start_index+2;
*counter_numbers=asciz_size;
asciz=(char*)calloc(asciz_size,sizeof(char));

				if(!asciz){
				*ERROR_FLAG=T;
		printf("cannot allocated memmory\nLINE NUMBER:%lu",(*COUNTER_LINES));
				return NULL;}


for(i=0;i<asciz_size-1;i++)
asciz[i]=buf[start_index++];
asciz[i]='\0';
return asciz;



}






int * reading_data_numbers(char * buf, boolean * ERROR_FLAG,unsigned long * COUNTER_LINES, int end_index_dot_op, int inst_op,unsigned int * counter_numbers){

int * temp=NULL;
int index;
int digit_start,digit_end,digit_size;
int * OPERATORS_TABLE=NULL;
char * number=NULL;
boolean DIGIT=F;
boolean COMMA=F;
boolean SIGN=F;
int i;


	if(end_index_dot_op+1>=strlen(buf)){
	printf("expcted READING DATA\n LINE NUMBER: %lu",(*COUNTER_LINES));
	*ERROR_FLAG=T;
	return NULL;}

		
	
	if(buf[end_index_dot_op+1]!=' '&& buf[end_index_dot_op+1]!='\t'){
printf("expcted space or tab between data and the name of method\n LINE NUMBER: %lu",(*COUNTER_LINES));
	*ERROR_FLAG=T;
	return NULL;}


end_index_dot_op++;


for(index=end_index_dot_op;index<strlen(buf) && buf[index]!='\n';index++){

	
	if(DIGIT==T && COMMA==T){


	digit_size=digit_end-digit_start+2;
	number=(char *)calloc(digit_size,sizeof(char));


				if(!number){
				*ERROR_FLAG=T;
		printf("cannot allocated memmory\nLINE NUMBER:%lu",(*COUNTER_LINES));
				return NULL;}


	
	for(i=0;i<digit_size-1;i++)
	number[i]=buf[digit_start++];
	number[i]='\0';


if(*counter_numbers==0){
*counter_numbers=*counter_numbers+1;
OPERATORS_TABLE=(int*)calloc((*counter_numbers),sizeof(int));

				if(!OPERATORS_TABLE){
				*ERROR_FLAG=T;
		printf("cannot allocated memmory\nLINE NUMBER:%lu",(*COUNTER_LINES));
				return NULL;}

	if(SIGN==T)
			
	OPERATORS_TABLE[(*counter_numbers)-1]=-atoi(number);
			
		else
			
		OPERATORS_TABLE[(*counter_numbers)-1]=atoi(number);
}


else{

*counter_numbers=*counter_numbers+1;
temp=(int*)realloc(OPERATORS_TABLE,(*counter_numbers)*sizeof(int));

				if(!temp){
				*ERROR_FLAG=T;
		printf("cannot allocated memmory\nLINE NUMBER:%lu",(*COUNTER_LINES));
				return NULL;}
OPERATORS_TABLE=temp;

	if(SIGN==T)
			
	OPERATORS_TABLE[(*counter_numbers)-1]=-atoi(number);
			
		else
			
		OPERATORS_TABLE[(*counter_numbers)-1]=atoi(number);


}


DIGIT=F;
COMMA=F;
SIGN=F;

}




		if(buf[index]==' ' || buf[index]=='\t')
		continue;


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



 
printf("expect sign,comma or digit\nLINE NUMBER:%lu",(*COUNTER_LINES));
			*ERROR_FLAG=T;
			return NULL;

		}


if(DIGIT==T){


	digit_size=digit_end-digit_start+2;
	number=(char *)calloc(digit_size,sizeof(char));


				if(!number){
				*ERROR_FLAG=T;
		printf("cannot allocated memmory\nLINE NUMBER:%lu",(*COUNTER_LINES));
				return NULL;}


	
	for(i=0;i<digit_size-1;i++)
	number[i]=buf[digit_start++];
	number[i]='\0';


if(*counter_numbers==0){
*counter_numbers=*counter_numbers+1;
OPERATORS_TABLE=(int*)calloc((*counter_numbers),sizeof(int));

				if(!OPERATORS_TABLE){
				*ERROR_FLAG=T;
		printf("cannot allocated memmory\nLINE NUMBER:%lu",(*COUNTER_LINES));
				return NULL;}

	if(SIGN==T)
			
	OPERATORS_TABLE[(*counter_numbers)-1]=-atoi(number);
			
		else
			
		OPERATORS_TABLE[(*counter_numbers)-1]=atoi(number);
}


else{

(*counter_numbers)++;
temp=(int*)realloc(OPERATORS_TABLE,(*counter_numbers)*sizeof(int));

				if(!temp){
				*ERROR_FLAG=T;
		printf("cannot allocated memmory\nLINE NUMBER:%lu",(*COUNTER_LINES));
				return NULL;}
OPERATORS_TABLE=temp;

	if(SIGN==T)
			
	OPERATORS_TABLE[(*counter_numbers)-1]=-atoi(number);
			
		else
			
		OPERATORS_TABLE[(*counter_numbers)-1]=atoi(number);


		}




	}

return OPERATORS_TABLE;

}


int operation_type(char * buf,int start_index_dot_op,int end_index_dot_op,char ** instruction_table,char ** dot_table,type WORD_TYPE){

int SIZE_OP=end_index_dot_op-start_index_dot_op+2;
int i,j;
char * temp;
temp=(char*)calloc(SIZE_OP,sizeof(char));
temp[SIZE_OP-1]='\0';

for(i=0;i<SIZE_OP-1;i++)
temp[i]=buf[start_index_dot_op++];

	if (WORD_TYPE==CODE){
	for(j=0;j<=26;j++){
	if(strcmp(temp,instruction_table[j])==0){
	return j;}}}
		
		if (WORD_TYPE==DATA){
		for(j=0;j<=3;j++){
		if(strcmp(temp,dot_table[j])==0){
		return j;}}}

return DEFAULT;
}


