#include "header.h"

ptr_img_data data_to_binar(int data_type,long * DC,unsigned int * COUNTER_DATA, ptr_img_data DATA_IMAGE, int * OPERATORS_TABLE , unsigned int * counter_numbers,char * asciz,boolean * ERROR_FLAG, unsigned long * COUNTER_LINES,int num_of_file ){

int limit_up,limit_down;
int i=0;
int index;
unsigned int calc;
int * asist=NULL;
int size;
ptr_img_data temp=NULL;

*COUNTER_DATA=*COUNTER_DATA+1;

if(*COUNTER_DATA==0){
	DATA_IMAGE=(ptr_img_data)calloc((*COUNTER_DATA),sizeof(img_data));
				if (!DATA_IMAGE){
		printf("cannot allocate memory\nLINE NUMBER:%lu",(*COUNTER_LINES));
				*ERROR_FLAG=T;
				return NULL;}
			}


	else{
temp=(ptr_img_data)realloc(DATA_IMAGE,((*COUNTER_DATA)*sizeof(img_data)));
			if (!temp){
		printf("cannot allocate memory\nLINE NUMBER:%lu",(*COUNTER_LINES));
			*ERROR_FLAG=T;;
			return NULL;}
	DATA_IMAGE=temp;
		}

if(data_type<=2)
{

	if(data_type<2)	
	size=(data_type*8)+8;
		else
		size=32;

	


DATA_IMAGE[*COUNTER_DATA-1].code=(int*)calloc((*counter_numbers)*size,sizeof(int));
		if(!DATA_IMAGE[*COUNTER_DATA-1].code){
	printf("cannot allocate memory\nLINE NUMBER:%lu",(*COUNTER_LINES));
				*ERROR_FLAG=T;
				return NULL;}

	limit_down=0;
	limit_up=size-1;
	
	for(index=0;index<(*counter_numbers);index++){
	asist=digit_to_binar(OPERATORS_TABLE[index],size,*COUNTER_LINES);
		for(limit_down;limit_down<=limit_up;limit_down++)
		DATA_IMAGE[*COUNTER_DATA-1].code[limit_down]=asist[i++];
	limit_up+=size;
	i=0;}

		
	DATA_IMAGE[*COUNTER_DATA-1].file_number=num_of_file;	
	DATA_IMAGE[*COUNTER_DATA-1].size_of_code=(*counter_numbers)*size;	
	DATA_IMAGE[*COUNTER_DATA-1].address=*DC;
	DATA_IMAGE[*COUNTER_DATA-1].status=1;
	DATA_IMAGE[*COUNTER_DATA-1].op_code=DEFAULT;
	*DC+=(*counter_numbers)*(size/8);


return DATA_IMAGE;
}




calc=strlen(asciz)+1;
size=8;


	

	DATA_IMAGE[*COUNTER_DATA-1].code=(int*)calloc(calc*size,sizeof(int));

			if(!DATA_IMAGE[*COUNTER_DATA-1].code){
	printf("cannot allocate memory\nLINE NUMBER:%lu",(*COUNTER_LINES));
				*ERROR_FLAG=T;
				return NULL;}


	
	limit_down=0;
	limit_up=7;
	for(index=0;index<calc-1;index++){
	asist=asciz_to_binar(asciz[index],*COUNTER_LINES);
		for(limit_down;limit_down<=limit_up;limit_down++)
		DATA_IMAGE[(*COUNTER_DATA)-1].code[limit_down]=asist[i++];
	limit_up+=8;
	i=0;}
			
	DATA_IMAGE[*COUNTER_DATA-1].file_number=num_of_file;	
	DATA_IMAGE[*COUNTER_DATA-1].size_of_code=calc*size;
	DATA_IMAGE[(*COUNTER_DATA)-1].address=*DC;
	DATA_IMAGE[(*COUNTER_DATA)-1].status=1;
	DATA_IMAGE[(*COUNTER_DATA)-1].op_code=DEFAULT;
	*DC+=calc;

return DATA_IMAGE;
	


}






ptr_img_data to_binar(char * label_operator , int * OPERATORS_TABLE,int inst_op,long * IC,unsigned int * COUNTER_DATA,ptr_img_data DATA_IMAGE ,boolean * ERROR_FLAG,unsigned long * COUNTER_LINES,unsigned int * COUNTER_SYMBOLS,ptr_symbol SYMBOL_TABLE,int num_of_file){

int * asist=NULL;
ptr_img_data temp=NULL;


*COUNTER_DATA=*COUNTER_DATA+1;

if(*COUNTER_DATA==0){
	
	DATA_IMAGE=(ptr_img_data)calloc((*COUNTER_DATA),sizeof(img_data));
				if (!DATA_IMAGE){
		printf("cannot allocate memory\nLINE NUMBER:%lu",(*COUNTER_LINES));
				*ERROR_FLAG=T;
				return NULL;}
			}
else{
	
temp=(ptr_img_data)realloc(DATA_IMAGE,*COUNTER_DATA*sizeof(img_data));
			if (!temp){
		printf("cannot allocate memory\nLINE NUMBER:%lu",(*COUNTER_LINES));
			*ERROR_FLAG=T;
			return NULL;}
	DATA_IMAGE=temp;
	}
	



		if(inst_op<=4 && inst_op>=0){
DATA_IMAGE[(*COUNTER_DATA)-1].status=1;
asist=decimal_to_binar_R(inst_op+1,OPERATORS_TABLE[0],OPERATORS_TABLE[1],OPERATORS_TABLE[2],0);}




		if(inst_op>=5 && inst_op<=7){
DATA_IMAGE[(*COUNTER_DATA)-1].status=1;
asist=decimal_to_binar_R(inst_op-4,OPERATORS_TABLE[1],0,OPERATORS_TABLE[0],1);}





		if((inst_op>=8 && inst_op<=12)||(inst_op>=17 && inst_op<=22)){

DATA_IMAGE[(*COUNTER_DATA)-1].status=1;
asist=decimal_to_binar_I(OPERATORS_TABLE[2],OPERATORS_TABLE[1],OPERATORS_TABLE[0],inst_op+2);}




		if(inst_op>=13 && inst_op<=16){
			
			DATA_IMAGE[(*COUNTER_DATA)-1].status=0;
asist=decimal_to_binar_I(0,OPERATORS_TABLE[1],OPERATORS_TABLE[0],inst_op+2);
strcpy(DATA_IMAGE[(*COUNTER_DATA)-1].symbol_as_operand,label_operator);
				}

		

		if(inst_op==23){

			if(OPERATORS_TABLE[0]==1){
			DATA_IMAGE[(*COUNTER_DATA)-1].status=1;
asist=decimal_to_binar_J(OPERATORS_TABLE[1],OPERATORS_TABLE[0],30);}

			else{
			DATA_IMAGE[(*COUNTER_DATA)-1].status=0;
asist=decimal_to_binar_J(0,OPERATORS_TABLE[0],30);
strcpy(DATA_IMAGE[*COUNTER_DATA-1].symbol_as_operand,label_operator);}
}
	
				
	if(inst_op==24){
	DATA_IMAGE[(*COUNTER_DATA)-1].status=0;
asist=decimal_to_binar_J(0,0,31);
strcpy(DATA_IMAGE[*COUNTER_DATA-1].symbol_as_operand,label_operator);}


	if(inst_op==25){
	DATA_IMAGE[(*COUNTER_DATA)-1].status=0;
	strcpy(DATA_IMAGE[*COUNTER_DATA-1].symbol_as_operand,label_operator);
asist=decimal_to_binar_J(0,0,32);}	



	if(inst_op==26){
	DATA_IMAGE[*COUNTER_DATA-1].status=1;
	asist=decimal_to_binar_J(0,0,63);}
	
	

	DATA_IMAGE[*COUNTER_DATA-1].op_code=inst_op;
	DATA_IMAGE[*COUNTER_DATA-1].file_number=num_of_file;
	DATA_IMAGE[*COUNTER_DATA-1].code=asist;
	DATA_IMAGE[*COUNTER_DATA-1].address=*IC;
	*IC+=4;
	return DATA_IMAGE;

}
