#include "header.h"

int complete_data_table(ptr_symbol SYMBOL_TABLE,ptr_img_data DATA_IMAGE,unsigned int COUNTER_DATA,unsigned int COUNTER_SYMBOLS){

int i;
int index_data;
int index_symbol;
long calc;
boolean status=F;
boolean inner_status=F;
int * temp;


	for(index_data=0;index_data<COUNTER_DATA;index_data++){

if(DATA_IMAGE[index_data].symbol_as_operand!=NULL && DATA_IMAGE[index_data].status==0){
status=T;


if(DATA_IMAGE[index_data].op_code>=13 && DATA_IMAGE[index_data].op_code<=16){	

for(index_symbol=0;index_symbol<COUNTER_SYMBOLS;index_symbol++){
if(strcmp(SYMBOL_TABLE[index_symbol].name,DATA_IMAGE[index_data].symbol_as_operand)==0){
if(SYMBOL_TABLE[index_symbol].file_number==DATA_IMAGE[index_data].file_number){
	inner_status=T;
	calc=SYMBOL_TABLE[index_symbol].address-DATA_IMAGE[index_data].address;
	temp=number_to_binar(calc,16);
		for(i=0;i<=15;i++)
	DATA_IMAGE[index_data].code[i+16]=temp[i];
	}}}
			

		

		}/*CLOSING 13-16*/


if(DATA_IMAGE[index_data].op_code>=23 && DATA_IMAGE[index_data].op_code<=25){

for(index_symbol=0;index_symbol<COUNTER_SYMBOLS;index_symbol++){
if(strcmp(SYMBOL_TABLE[index_symbol].name,DATA_IMAGE[index_data].symbol_as_operand)==0){
inner_status=T;
if(SYMBOL_TABLE[index_symbol].file_number==DATA_IMAGE[index_data].file_number){
calc=SYMBOL_TABLE[index_symbol].address;
temp=number_to_binar(calc,25);
	for(i=0;i<=24;i++)
	DATA_IMAGE[index_data].code[i+7]=temp[i];

	

	}}}
	

	}/*CLOSING 23-25*/



if(status==T && inner_status==F){
printf("%s",DATA_IMAGE[index_data].symbol_as_operand);
printf("couldnt find your symbol opperand\n");
return DEFAULT;}

status=F;
inner_status=F;


}/*closing if*/




}/*closing loop DATA IMAGE*/
return SUCCESSFUL;

}






int checking_entry_symbol_for_extern(ptr_symbol SYMBOL_TABLE, unsigned int COUNTER_SYMBOLS){
int index;
int inner_index;
boolean ENTRY_FOUND=F;
boolean IS_EXTERN=F;

if(SYMBOL_TABLE!=NULL){
	for(index=0;index<COUNTER_SYMBOLS;index++){	
		if(strcmp(SYMBOL_TABLE[index].symbol_status,"EXTERNAL")==0){
			IS_EXTERN=T;
	 for(inner_index=0;inner_index<COUNTER_SYMBOLS && IS_EXTERN==T;index++){

	if(SYMBOL_TABLE[inner_index].file_number!=SYMBOL_TABLE[index].file_number){
	if(strcmp(SYMBOL_TABLE[inner_index].name,SYMBOL_TABLE[index].name)==0){
	if(strcmp(SYMBOL_TABLE[inner_index].symbol_status,"ENTRY")==0){
		ENTRY_FOUND=T;
		break;}}}}
	

	if(IS_EXTERN==T && ENTRY_FOUND==F){
	printf("\nextern without entry\n");
	return DEFAULT;}


ENTRY_FOUND=F;
IS_EXTERN=F;

}}}

return SUCCESSFUL;
}





void making_output_files(ptr_symbol SYMBOL_TABLE,ptr_img_data DATA_IMAGE,int num_of_file,unsigned int COUNTER_DATA,unsigned int COUNTER_SYMBOLS,char ** argv){
int i;
int counter_info=0;
long counter_code=0;
long counter_data=0;
int index_max;
int index_min;
ptr_img_data DATA_IMAGE_FILE=NULL;
ptr_img_data pointer_temp=NULL;
img_data struct_temp;
char * name_of_file_source=NULL;
char * name_of_file_extern=NULL;
char * name_of_file_entry=NULL;
char * symbol_name;
int * binar;
int hex_temp=0;
int index;
int inner_index;
long calc1;
long calc2;
FILE * file_temp;
int text_index=0;
int size_of_name;
int size_of_code;
int inner_counter=0;
int extern_show=0;
int entry_show=0;
int * temp_code;
boolean entry_found=F;
boolean extern_found=F;
long address;
boolean first_time=F;
int k,j,p;
int symbol_size;




			if(COUNTER_DATA==0){
	printf("EXCEPTED ELLEMENTS IN DATA_TABLE");
				return;}
	

	for(index=0;index<COUNTER_DATA;index++){

		if(DATA_IMAGE[index].file_number==num_of_file){

		counter_info++;


		if(counter_info>1){
		
pointer_temp=(ptr_img_data)realloc(DATA_IMAGE_FILE,counter_info*sizeof(img_data));
				if (!pointer_temp){
		printf("cannot allocate memory\nLINE NUMBER");
				return;}	
		DATA_IMAGE_FILE=pointer_temp;}


	if(counter_info==1)
	DATA_IMAGE_FILE=(ptr_img_data)calloc(counter_info,sizeof(img_data));


	

	if(DATA_IMAGE[index].op_code!=DEFAULT){

		DATA_IMAGE_FILE[counter_info-1].code=(int*)calloc(32,sizeof(int));
		for(inner_index=0;inner_index<32;inner_index++)
DATA_IMAGE_FILE[counter_info-1].code[inner_index]=DATA_IMAGE[index].code[inner_index];



	
strcpy((DATA_IMAGE_FILE[counter_info-1].symbol_as_operand),(DATA_IMAGE[index].symbol_as_operand));
}


if(DATA_IMAGE[index].op_code==DEFAULT){

DATA_IMAGE_FILE[counter_info-1].size_of_code=DATA_IMAGE[index].size_of_code;
DATA_IMAGE_FILE[counter_info-1].code=(int*)calloc(DATA_IMAGE[index].size_of_code,sizeof(int));

for(inner_index=0;inner_index<DATA_IMAGE[index].size_of_code;inner_index++)
DATA_IMAGE_FILE[counter_info-1].code[inner_index]=DATA_IMAGE[index].code[inner_index];

}

DATA_IMAGE_FILE[counter_info-1].op_code=DATA_IMAGE[index].op_code;
DATA_IMAGE_FILE[counter_info-1].address=DATA_IMAGE[index].address;
DATA_IMAGE_FILE[counter_info-1].file_number=DATA_IMAGE[index].file_number;






}}




if(counter_info>1){

	for(k=0;k<counter_info;k++){
		
		for(j=k+1;j<counter_info;j++){
		
			if(DATA_IMAGE_FILE[k].address>DATA_IMAGE_FILE[j].address){

	

		
				struct_temp=DATA_IMAGE_FILE[k];
				DATA_IMAGE_FILE[k]=DATA_IMAGE_FILE[j];
				DATA_IMAGE_FILE[j]=struct_temp;
				}
			}
		}
	}


																											


for(index=0;index<counter_info;index++)
{

if(DATA_IMAGE_FILE[index].op_code==DEFAULT)
break;
}


counter_code=DATA_IMAGE_FILE[index].address-DATA_IMAGE_FILE[0].address;
calc2=DATA_IMAGE_FILE[counter_info-1].size_of_code/8;
calc1=calc2+DATA_IMAGE_FILE[counter_info-1].address-DATA_IMAGE_FILE[0].address;
counter_data=calc1-counter_code;



size_of_name=strlen(argv[num_of_file])+1;
name_of_file_source=(char*)calloc(size_of_name,sizeof(char));
strcpy(name_of_file_source,argv[num_of_file]);
	for(index=0;index<size_of_name-1;index++)
	{
		while(name_of_file_source[index]!='.')
		index++;
	name_of_file_source[index++]='.';
	name_of_file_source[index++]='o';
	name_of_file_source[index++]='b';
	name_of_file_source[index]='\0';
	}
file_temp=fopen(name_of_file_source,"w");
fprintf(file_temp,"  %ld  \t  %ld      \n",counter_code,counter_data);





for(index=0;index<counter_info;index++){
	
	

	if(DATA_IMAGE_FILE[index].op_code==DEFAULT)
	break;




fprintf(file_temp," %ld \t  ",DATA_IMAGE_FILE[index].address);

	index_max=31;
	index_min=24;

	for(inner_index=0;inner_index<4;inner_index++){

	
	

hex_temp=binar_to_hex(DATA_IMAGE_FILE[index].code,index_max,index_min);	

	fprintf(file_temp," %02X ",hex_temp);
	
	
	index_max=index_max-8;
	index_min=index_min-8;
				}

fprintf(file_temp,"  %c  ",'\n');

}


inner_counter=0;
for(index;index<counter_info;index++)
{

if(first_time==F){
address=DATA_IMAGE_FILE[index].address;
fprintf(file_temp,"  %ld   ",address);}

first_time=T;

size_of_code=DATA_IMAGE_FILE[index].size_of_code;
index_max=size_of_code-1;
index_min=size_of_code-8;



for(inner_index=0;inner_index<(size_of_code)/8;inner_index++)
{

if(inner_counter==4){
address+=4;
fprintf(file_temp,"%c",'\n');
fprintf(file_temp,"   %ld \t  ",address);
inner_counter=0;
}
		
hex_temp=binar_to_hex(DATA_IMAGE_FILE[index].code,index_max,index_min);	
fprintf(file_temp," %02X ",hex_temp);
index_max-=8;
index_min-=8;
inner_counter++;

}

}
fclose(file_temp);




for(index=0;index<COUNTER_SYMBOLS;index++){

	for(inner_index=0;inner_index<counter_info;inner_index++){

	if(SYMBOL_TABLE[index].file_number==num_of_file){
	
		if(SYMBOL_TABLE[index].symbol_status!=NULL){
	
			if(strcmp(SYMBOL_TABLE[index].symbol_status,"ENTRY")==0){

		symbol_name=(char*)calloc(LABEL_MAX_SIZE,sizeof(char));
		
	strcpy(symbol_name,SYMBOL_TABLE[index].name);


		
		if(DATA_IMAGE_FILE[inner_index].symbol_as_operand!=NULL){
	if(strcmp(DATA_IMAGE_FILE[inner_index].symbol_as_operand,symbol_name)==0){
		entry_found=T;
		entry_show++;}}

	if(entry_found==F)
		continue;

	
	if(entry_show==1){
	size_of_name=strlen(argv[num_of_file])+2;
	name_of_file_entry=(char*)calloc(size_of_name,sizeof(char));
	strcpy(name_of_file_entry,argv[num_of_file]);
			for(i=0;i<size_of_name-1;i++)
			{
			while(name_of_file_entry[i]!='.')
			i++;
		name_of_file_entry[i++]='.';
		name_of_file_entry[i++]='e';
		name_of_file_entry[i++]='n';
		name_of_file_entry[i++]='t';
		name_of_file_entry[i]='\0';
			}
file_temp=fopen(name_of_file_entry,"w");
fprintf(file_temp,"  %s   %ld   %c ",symbol_name,SYMBOL_TABLE[index].address,'\n');
		
	}


fprintf(file_temp,"  %s   %ld   %c ",symbol_name,DATA_IMAGE_FILE[inner_index].address,'\n');
entry_found=F;
free(symbol_name);
}}}}}



for(index=0;index<COUNTER_SYMBOLS;index++){

	for(inner_index=0;inner_index<counter_info;inner_index++){

	if(SYMBOL_TABLE[index].file_number==num_of_file){
	
		if(SYMBOL_TABLE[index].symbol_status!=NULL){
	
			if(strcmp(SYMBOL_TABLE[index].symbol_status,"EXTERNAL")==0){

		symbol_name=(char*)calloc(LABEL_MAX_SIZE,sizeof(char));
		
	strcpy(symbol_name,SYMBOL_TABLE[index].name);


		
		if(DATA_IMAGE_FILE[inner_index].symbol_as_operand!=NULL){
	if(strcmp(DATA_IMAGE_FILE[inner_index].symbol_as_operand,symbol_name)==0){
		extern_found=T;
		extern_show++;}}

	if(extern_found==F)
		continue;

	
	if(extern_show==1){
	size_of_name=strlen(argv[num_of_file])+2;
	name_of_file_extern=(char*)calloc(size_of_name,sizeof(char));
	strcpy(name_of_file_extern,argv[num_of_file]);
			for(i=0;i<size_of_name-1;i++)
			{
			while(name_of_file_extern[i]!='.')
			i++;
		name_of_file_extern[i++]='.';
		name_of_file_extern[i++]='e';
		name_of_file_extern[i++]='x';
		name_of_file_extern[i++]='t';
		name_of_file_extern[i]='\0';
			}
file_temp=fopen(name_of_file_extern,"w");
fprintf(file_temp,"  %s   %ld   %c ",symbol_name,SYMBOL_TABLE[index].address,'\n');
		
	}


fprintf(file_temp,"  %s   %ld   %c ",symbol_name,DATA_IMAGE_FILE[inner_index].address,'\n');
extern_found=F;
free(symbol_name);
}}}}}




}
