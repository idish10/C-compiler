#include "header.h"

int main(int argc, char ** argv){
int suffix=0;
char * label_operator=NULL;
char * asciz=NULL;
int * OPERATORS_TABLE=NULL;
char  * buf=NULL;
ptr_symbol SYMBOL_TABLE=NULL; 
ptr_img_data DATA_IMAGE=NULL;
unsigned int COUNTER_SYMBOLS=0; 
unsigned int COUNTER_DATA=0; 
char *dot_table[4]={"db","dh","dw","asciz"};
char *instruction_table[27]={"add","sub","and","or","nor","move","mvhi","mvlo","addi","subi","andi","ori","nori","bne","beq","blt","bgt","lb","sb","lw","sw","lh","sh","jmp","la","call","stop"};
int inst_op;
int z,j;
int temp_index=0;
int index=0;
int index_start=0;
int index_end=0;
int start_index_dot_op=0;
int end_index_dot_op=0;
int SIZE_OP;
unsigned long COUNTER_LINES=0;
unsigned int counter_numbers=0;
long DC=0;
long IC=100;
type WORD_TYPE;
boolean STOP=F;
boolean ERROR_FLAG=F;
boolean LABEL_FLAG=F;
FILE * file_temp=NULL;
int num_of_file=0;
char * status=NULL;


if (argc<2){
printf("YOU HAVE TO INCLUDE AT LEAST 1 TEXT FILE TO RUN THE PROGRAM \n");
exit(0);}




for(num_of_file=1;num_of_file<argc;num_of_file++){





	for(suffix=0;suffix<strlen(argv[num_of_file]);suffix++){

			if(argv[num_of_file][suffix]!='.')
			continue;


			suffix++;
			if(argv[num_of_file][suffix++]=='a'){
			if(argv[num_of_file][suffix]=='s')
			break;}

		printf("open file failed wrong fromat");
		exit(0);}








file_temp=fopen(argv[num_of_file],"r");

	if(file_temp==NULL){
printf("open file failed");
	exit(0);}
	
	
	buf=(char*)calloc(LINE_SIZE+1,sizeof(char));

	while(fgets(buf,LINE_SIZE+1,file_temp)){
	 
	



for(index=0; index<strlen(buf) && buf[index]!='\n' ;index++){


	if(STOP==T){
	STOP=F;
	break;}



	if(buf[index]==' '||buf[index]=='\t')
	continue;
		

	

	if(buf[index]==';')
	break;



	if(isalpha(buf[index])!=0) {
		
		if(LABEL_FLAG==F){
		index_start=index;	
		index_end=index;

while(index+1<strlen(buf) &&(isalpha(buf[index+1])!=0||isdigit(buf[index+1])!=0))
	index++;


		index_end=index;


	if(index+1<strlen(buf) && buf[index+1]==':'){
				

			index++;
			LABEL_FLAG=T;
			continue;}


		else	
	index=index_start;

		}




	
		
	
		

		

		if(islower(buf[index])!=0){	
		WORD_TYPE=CODE;
		start_index_dot_op=index;
		end_index_dot_op=index;
		while(index+1<strlen(buf) && islower(buf[index+1])!=0)	
			index++;
		end_index_dot_op=index;



inst_op=operation_type(buf,start_index_dot_op,end_index_dot_op, instruction_table, dot_table,WORD_TYPE);
				if(inst_op==DEFAULT){  
printf("\nexpectsed R/I/J command \nLINE NUMBER: %lu\n",COUNTER_LINES);
	putchar(buf[start_index_dot_op]);
	putchar(buf[end_index_dot_op]);
				ERROR_FLAG=T;	
				break;}



		
if(LABEL_FLAG==T){	

SYMBOL_TABLE=add_symbol(buf,index_start,index_end,&COUNTER_SYMBOLS,SYMBOL_TABLE,&ERROR_FLAG,&COUNTER_LINES,instruction_table,dot_table,&IC,&DC,WORD_TYPE,num_of_file);	
if(SYMBOL_TABLE==NULL)
break;}

label_operator=(char*)calloc(LABEL_MAX_SIZE,sizeof(char));
	
if(inst_op>=0 && inst_op<=7){	
	
OPERATORS_TABLE=checking_arguments_R(buf,&ERROR_FLAG,&COUNTER_LINES,end_index_dot_op,inst_op);
if(OPERATORS_TABLE==NULL)
break;
}



if((inst_op>=8 && inst_op<=12)||(inst_op>=17 && inst_op<=22)){
OPERATORS_TABLE=checking_arguments_I_aritmathic(buf,&ERROR_FLAG,&COUNTER_LINES, end_index_dot_op,inst_op);
if(OPERATORS_TABLE==NULL)
break;
}


if(inst_op>=13 && inst_op<=16){
OPERATORS_TABLE=I_coditional(buf, &ERROR_FLAG, &COUNTER_LINES,end_index_dot_op, inst_op,label_operator);
if(OPERATORS_TABLE==NULL)
break;
}




if(inst_op==23){
OPERATORS_TABLE=checking_arguments_jmp( buf, &ERROR_FLAG, &COUNTER_LINES, end_index_dot_op, inst_op, label_operator,OPERATORS_TABLE);
if(OPERATORS_TABLE==NULL)
break;}



if(inst_op==24 || inst_op==25){

if(checking_arguments_la_and_call(buf,&ERROR_FLAG,&COUNTER_LINES,end_index_dot_op,label_operator)==DEFAULT)
break;}

if(inst_op==26){	

		if(end_index_dot_op+1<strlen(buf)){
		
		
if(buf[end_index_dot_op+1]==' '|| buf[end_index_dot_op+1]=='\t' || buf[end_index_dot_op+1]=='\n')
	end_index_dot_op++;}

		else{
		printf("%c",buf[end_index_dot_op+1]);
		ERROR_FLAG=T;
		printf("space or tab expected here \nLINE NUMBER:%lu",(COUNTER_LINES));
		break;}	

for(index=end_index_dot_op; index<strlen(buf) && buf[index]!='\n' ;index++){

	if(buf[index]==' '||buf[index]=='\t')
	continue;
		
		
		ERROR_FLAG=T;
		printf("space or tab expected \nLINE NUMBER:%lu",(COUNTER_LINES));
		break;}

	}





DATA_IMAGE=to_binar(label_operator , OPERATORS_TABLE, inst_op,&IC,&COUNTER_DATA,DATA_IMAGE ,&ERROR_FLAG,&COUNTER_LINES,&COUNTER_SYMBOLS,SYMBOL_TABLE,num_of_file);
break;


			}/*end if is lower*/
		}/*end if is alpha*/


if(buf[index]=='.'){

	if(index+1>strlen(buf) || islower(buf[index+1])==0){
	printf("\n . lower excepted \n LINE NUMBER: %lu",COUNTER_LINES);
			ERROR_FLAG=T;
			break;}

	index++;
	temp_index=index;
	start_index_dot_op=index;	
	end_index_dot_op=index;	

			while(index+1<strlen(buf) && islower(buf[index+1])!=0)
			index++;
			end_index_dot_op=index;
			
SIZE_OP=end_index_dot_op-start_index_dot_op+2;
status=(char *)calloc(SIZE_OP,sizeof(char));
	for(j=0;j<SIZE_OP-1;j++)
status[j]=buf[start_index_dot_op++];
status[j]='\0';

if((strcmp(status,"entry")==0)||(strcmp(status,"extern")==0)){


SYMBOL_TABLE=entry_extern(buf ,status,end_index_dot_op,SYMBOL_TABLE, &COUNTER_SYMBOLS,&ERROR_FLAG, num_of_file,&COUNTER_LINES,instruction_table,dot_table);
STOP=T;
break;}



WORD_TYPE=DATA;
inst_op=operation_type(buf,temp_index,end_index_dot_op, instruction_table, dot_table,WORD_TYPE);

		if(inst_op==DEFAULT){
printf("\nyour . operation doesnt exist in the dot_table\n LINE NUMBER: %lu",COUNTER_LINES);
			ERROR_FLAG=T;
			break;}


if(LABEL_FLAG==T){	

SYMBOL_TABLE=add_symbol(buf,index_start,index_end,&COUNTER_SYMBOLS,SYMBOL_TABLE,&ERROR_FLAG,&COUNTER_LINES,instruction_table,dot_table,&IC,&DC,WORD_TYPE,num_of_file);	
if(SYMBOL_TABLE==NULL)
break;}

if(inst_op>=0 && inst_op<=2){

OPERATORS_TABLE=reading_data_numbers(buf, &ERROR_FLAG, &COUNTER_LINES, end_index_dot_op, inst_op,&counter_numbers);


}


if(inst_op==3){
asciz=reading_data_asciz(buf, &ERROR_FLAG, &COUNTER_LINES, end_index_dot_op, inst_op,&counter_numbers);

}

if(asciz==NULL && OPERATORS_TABLE==NULL)
break;

DATA_IMAGE=data_to_binar(inst_op,&DC,&COUNTER_DATA,DATA_IMAGE,OPERATORS_TABLE,&counter_numbers,asciz,&ERROR_FLAG,&COUNTER_LINES,num_of_file);
STOP=T;
}/*if dot*/	



}/*end for of line*/	


counter_numbers=0;
COUNTER_LINES++;
WORD_TYPE=WITHOUT;
LABEL_FLAG=F;


}/*end while fgets(buf..... */
	

if(COUNTER_SYMBOLS!=0){
	for(index=0;index<COUNTER_SYMBOLS;index++){

	if(SYMBOL_TABLE[index].ENTRY_FLAG==1){
printf("\nENTRY SYMBOL WITHOUT DEFINITION");
	exit(0);}

if(strcmp(SYMBOL_TABLE[index].symbol_type,"DATA")==0 && SYMBOL_TABLE[index].file_number==num_of_file)
SYMBOL_TABLE[index].address+=IC;}}

if(COUNTER_DATA!=0){
	for(index=0;index<COUNTER_DATA;index++){


if(DATA_IMAGE[index].op_code==DEFAULT && DATA_IMAGE[index].file_number==num_of_file)
DATA_IMAGE[index].address+=IC;}}
IC=IC+DC;
DC=0;
COUNTER_LINES=1;
fclose(file_temp);


}/*end for of files*/


if(ERROR_FLAG==T){

printf("\nERROR appeared\n");
exit(0);}




if(checking_entry_symbol_for_extern(SYMBOL_TABLE,COUNTER_SYMBOLS)==DEFAULT)
exit(0);



if(complete_data_table(SYMBOL_TABLE,DATA_IMAGE,COUNTER_DATA,COUNTER_SYMBOLS)==DEFAULT)
exit(0);



for(num_of_file=1;num_of_file<argc;num_of_file++)
making_output_files(SYMBOL_TABLE,DATA_IMAGE,num_of_file,COUNTER_DATA,COUNTER_SYMBOLS,argv);





return 0;

}

