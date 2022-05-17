
#include "header.h"
ptr_symbol entry_extern(char * buf ,char * status,int end_index_dot_op,ptr_symbol SYMBOL_TABLE, unsigned int * COUNTER_SYMBOLS, boolean * ERROR_FLAG, int num_of_file,unsigned long * COUNTER_LINES,char ** instruction_table, char **dot_table){

ptr_symbol temp=NULL;
int i,k,index,SIZE_TAG,end_tag,start_tag;
char * tag=NULL;




	if(buf[end_index_dot_op+1]!=' ' && buf[end_index_dot_op+1]!='\t'){
printf("expceted space or tab \n LINE NUMBER: %lu",(*COUNTER_LINES));
			*ERROR_FLAG=T;
			return NULL;}
	end_index_dot_op++;


for(index=end_index_dot_op;index<strlen(buf)&&buf[index]!='\n';index++){
		
		


if(buf[index]==' '||buf[index]=='\t')
	continue;


	if(isalpha(buf[index])!=0){
	
	
		
		start_tag=index;
		end_tag=index;

while(index+1<strlen(buf) && (isdigit(buf[index+1])!=0 ||isalpha(buf[index+1])!=0))
	index++;

end_tag=index;
	
SIZE_TAG=end_tag-start_tag+2;		



		if(SIZE_TAG>LABEL_MAX_SIZE){
printf("\nERROR-this tag is bigger than 32 bytes\n LINE NUMBER: %lu",(*COUNTER_LINES));
		*ERROR_FLAG=T;
		return NULL;}


tag=(char*)calloc(SIZE_TAG,sizeof(char));

			if(!tag){
			*ERROR_FLAG=T;
		printf("cannot allocated memmory\nLINE NUMBER:%lu",(*COUNTER_LINES));
			return NULL;}




	for(i=0;i<SIZE_TAG-1;i++)	
	tag[i]=buf[start_tag++];
	tag[i]='\0';


	
	if(operation_type(tag,0,SIZE_TAG-2, instruction_table, dot_table,CODE)!=DEFAULT){
printf("\nthis is already exist as an operation\nLINE NUMBER:%lu",*COUNTER_LINES);
		*ERROR_FLAG=T;
		return NULL;}


if(operation_type(tag,0,SIZE_TAG-2, instruction_table, dot_table,DATA)!=DEFAULT){
printf("\nthis is already exist as an operation\nLINE NUMBER:%lu",*COUNTER_LINES);
		*ERROR_FLAG=T;
		return NULL;}


continue;

		}


printf("\n %c \n" ,buf[index]);
printf("expect alpha letter or space\nLINE NUMBER:%lu",(*COUNTER_LINES));
			*ERROR_FLAG=T;
			return NULL;

	}


if(tag==NULL){
	printf("cant define your tag\nLINE NUMBER:%lu",(*COUNTER_LINES));
	*ERROR_FLAG=T;
	return NULL;}



if(strcmp(status,"extern")==0){




	if(*COUNTER_SYMBOLS!=0){




		for(k=0;k<*COUNTER_SYMBOLS;k++){

			if(strcmp(SYMBOL_TABLE[k].name,tag)==0){
					
																				if(SYMBOL_TABLE[k].file_number==num_of_file && strcmp(SYMBOL_TABLE[k].symbol_status,"EXTERNAL")==0)
return SYMBOL_TABLE;

if(SYMBOL_TABLE[k].file_number!=num_of_file){
if(strcmp(SYMBOL_TABLE[k].symbol_status,"ENTRY")==0||strcmp(SYMBOL_TABLE[k].symbol_status,"EXTERNAL")==0)
		continue;}
				
					*ERROR_FLAG=T;
	printf("\nthis tag is already defined\n LINE NUMBER: %lu",(*COUNTER_LINES));
					return NULL;}

		}

	*COUNTER_SYMBOLS=*COUNTER_SYMBOLS+1;
		
		

	temp=(ptr_symbol)realloc(SYMBOL_TABLE,(*COUNTER_SYMBOLS)*sizeof(symbol));
			if (!temp){
			*ERROR_FLAG=T;
	printf("\ncannot allocate memory\n LINE NUMBER: %lu",(*COUNTER_LINES));
			return NULL;}


	SYMBOL_TABLE=temp;
	SYMBOL_TABLE[*COUNTER_SYMBOLS-1].ENTRY_FLAG=0;		
	SYMBOL_TABLE[*COUNTER_SYMBOLS-1].file_number=num_of_file;
	strcpy(SYMBOL_TABLE[*COUNTER_SYMBOLS-1].name,tag);	
	SYMBOL_TABLE[*COUNTER_SYMBOLS-1].address=0;
	strcpy(SYMBOL_TABLE[*COUNTER_SYMBOLS-1].symbol_status,"EXTERNAL");
	strcpy(SYMBOL_TABLE[*COUNTER_SYMBOLS-1].symbol_type,"WITHOUT");
	return SYMBOL_TABLE;
	}


	if(*COUNTER_SYMBOLS==0){
			*COUNTER_SYMBOLS=*COUNTER_SYMBOLS+1;
	SYMBOL_TABLE=(ptr_symbol)calloc(*COUNTER_SYMBOLS,sizeof(symbol));

				if (!SYMBOL_TABLE){
	printf("\ncannot allocate memory\n LINE NUMBER: %lu",(*COUNTER_LINES));
				*ERROR_FLAG=T;
				return NULL;}


	SYMBOL_TABLE[0].ENTRY_FLAG=0;	
	SYMBOL_TABLE[0].file_number=num_of_file;
	strcpy(SYMBOL_TABLE[0].name,tag);
	SYMBOL_TABLE[0].address=0;
	strcpy(SYMBOL_TABLE[0].symbol_status,"EXTERNAL");
	strcpy(SYMBOL_TABLE[0].symbol_type,"WITHOUT");
	return SYMBOL_TABLE;
	}

}

if(strcmp(status,"entry")==0){


	if(*COUNTER_SYMBOLS!=0){






		for(k=0;k<*COUNTER_SYMBOLS;k++){

			if(strcmp(SYMBOL_TABLE[k].name,tag)==0){




		if(SYMBOL_TABLE[k].file_number!=num_of_file){
		if(strcmp(SYMBOL_TABLE[k].symbol_status,"EXTERNAL")==0)
					continue;}
		

	
		if(SYMBOL_TABLE[k].file_number==num_of_file){


		if(strcmp(SYMBOL_TABLE[k].symbol_type,"CODE")==0){
		strcpy(SYMBOL_TABLE[k].symbol_status,"ENTRY");
		return SYMBOL_TABLE;}

		if(strcmp(SYMBOL_TABLE[k].symbol_type,"DATA")==0){
		strcpy(SYMBOL_TABLE[k].symbol_status,"ENTRY");
		return SYMBOL_TABLE;}
	

		}


		*ERROR_FLAG=T;
	printf("\nthis tag is already defined\n LINE NUMBER: %lu",(*COUNTER_LINES));
					return NULL;

		}}


	
	




	*COUNTER_SYMBOLS=*COUNTER_SYMBOLS+1;
		

	temp=(ptr_symbol)realloc(SYMBOL_TABLE,(*COUNTER_SYMBOLS)*sizeof(symbol));
			if (!temp){
			*ERROR_FLAG=T;
	printf("\ncannot allocate memory\n LINE NUMBER: %lu",(*COUNTER_LINES));
			return NULL;}


	SYMBOL_TABLE=temp;		
	SYMBOL_TABLE[(*COUNTER_SYMBOLS)-1].ENTRY_FLAG=1;
	SYMBOL_TABLE[*COUNTER_SYMBOLS-1].file_number=num_of_file;
	strcpy(SYMBOL_TABLE[*COUNTER_SYMBOLS-1].name,tag);	
	strcpy(SYMBOL_TABLE[*COUNTER_SYMBOLS-1].symbol_status,"ENTRY");
	strcpy(SYMBOL_TABLE[*COUNTER_SYMBOLS-1].symbol_type,"WITHOUT");
	return SYMBOL_TABLE;
}

if(*COUNTER_SYMBOLS==0){
			*COUNTER_SYMBOLS=*COUNTER_SYMBOLS+1;
	SYMBOL_TABLE=(ptr_symbol)calloc(*COUNTER_SYMBOLS,sizeof(symbol));

				if (!SYMBOL_TABLE){
	printf("\ncannot allocate memory\n LINE NUMBER: %lu",(*COUNTER_LINES));
				*ERROR_FLAG=T;
				return NULL;}

	SYMBOL_TABLE[0].ENTRY_FLAG=1;	
	SYMBOL_TABLE[0].file_number=num_of_file;
	strcpy(SYMBOL_TABLE[0].name,tag);
	strcpy(SYMBOL_TABLE[0].symbol_status,"ENTRY");
	strcpy(SYMBOL_TABLE[0].symbol_type,"WITHOUT");
	return SYMBOL_TABLE;
	}

}
return NULL;
}




ptr_symbol add_symbol(char * buf, int index_start,int index_end,unsigned int  * COUNTER_SYMBOLS,ptr_symbol SYMBOL_TABLE,boolean * ERROR_FLAG, unsigned long * COUNTER_LINES,char ** instruction_table, char ** dot_table , long * IC, long *DC , type WORD_TYPE, int num_of_file){   

int SIZE;
char * tag=NULL;
ptr_symbol temp=NULL;
int ENTRY_index=DEFAULT;
boolean TEMP_ENTRY_FLAG=F;
int i,j;
		if(index_end-index_start>=LABEL_MAX_SIZE-1){
	printf("label limited to 31 char's\nLINE NUMBER:%lu",(*COUNTER_LINES));
			*ERROR_FLAG=T;
			return NULL;}

	
SIZE=index_end-index_start+2;
tag=(char*)calloc(SIZE,sizeof(char));
tag[SIZE-1]='\0';	
for(i=0;i<SIZE-1;i++)
tag[i]=buf[index_start++];

		
	if(operation_type(tag,0,SIZE-2, instruction_table, dot_table,CODE)!=DEFAULT){
printf("\nthis is already exist as an operation\nLINE NUMBER:%lu",*COUNTER_LINES);
		*ERROR_FLAG=T;
		return NULL;}


if(operation_type(tag,0,SIZE-2, instruction_table, dot_table,DATA)!=DEFAULT){
printf("\nthis is already exist as an operation\nLINE NUMBER:%lu",*COUNTER_LINES);
		*ERROR_FLAG=T;
		return NULL;}



if(*COUNTER_SYMBOLS!=0){


	for(j=0;j<*COUNTER_SYMBOLS;j++){

		if(strcmp(SYMBOL_TABLE[j].name,tag)==0){
				
			if(SYMBOL_TABLE[j].file_number==num_of_file){
			if(SYMBOL_TABLE[j].ENTRY_FLAG==1){
					ENTRY_index=j;
					TEMP_ENTRY_FLAG=T;
					continue;}}

			if(SYMBOL_TABLE[j].file_number!=num_of_file){
		if(strcmp(SYMBOL_TABLE[j].symbol_status,"EXTERNAL")==0)
				continue;}


	
printf("\nERROR-this tag already defined \n LINE NUMBER: %lu",*COUNTER_LINES);
				*ERROR_FLAG=T;
				return NULL;}
			}



	if(TEMP_ENTRY_FLAG==T){
	SYMBOL_TABLE[ENTRY_index].ENTRY_FLAG=0;

		if(WORD_TYPE==DATA){
	SYMBOL_TABLE[ENTRY_index].address=(*DC);
	strcpy(SYMBOL_TABLE[ENTRY_index].symbol_type,"DATA");}

		if(WORD_TYPE==CODE){
	SYMBOL_TABLE[ENTRY_index].address=(*IC);
	strcpy(SYMBOL_TABLE[ENTRY_index].symbol_type,"CODE");}
	
	return SYMBOL_TABLE;
	}



	*COUNTER_SYMBOLS=*COUNTER_SYMBOLS+1;

	temp=(ptr_symbol)realloc(SYMBOL_TABLE,(*COUNTER_SYMBOLS)*sizeof(symbol));
			if (!temp){
	printf("\ncannot allocate memory\n LINE NUMBER: %lu",(*COUNTER_LINES));
			*ERROR_FLAG=T;
			return NULL;}

	SYMBOL_TABLE=temp;
	strcpy(SYMBOL_TABLE[(*COUNTER_SYMBOLS)-1].symbol_status,"NONE");
	strcpy(SYMBOL_TABLE[(*COUNTER_SYMBOLS)-1].name,tag);
	SYMBOL_TABLE[(*COUNTER_SYMBOLS)-1].file_number=num_of_file;
	SYMBOL_TABLE[(*COUNTER_SYMBOLS)-1].ENTRY_FLAG=0;

		if(WORD_TYPE==DATA){
			
		strcpy(SYMBOL_TABLE[(*COUNTER_SYMBOLS)-1].symbol_type,"DATA");
			SYMBOL_TABLE[(*COUNTER_SYMBOLS)-1].address=(*DC);
			}

		if(WORD_TYPE==CODE){
		
				
		strcpy(SYMBOL_TABLE[(*COUNTER_SYMBOLS)-1].symbol_type,"CODE");
			SYMBOL_TABLE[(*COUNTER_SYMBOLS)-1].address=(*IC);
			}

return SYMBOL_TABLE;
	}



if(*COUNTER_SYMBOLS==0){
	*COUNTER_SYMBOLS=*COUNTER_SYMBOLS+1;
	SYMBOL_TABLE=malloc((*COUNTER_SYMBOLS)*sizeof(symbol));
		if (!SYMBOL_TABLE){
	printf("\ncannot allocate memory\n LINE NUMBER: %lu",*COUNTER_LINES);
		*ERROR_FLAG=T;
		return NULL;}

	strcpy(SYMBOL_TABLE[0].name,tag);
	SYMBOL_TABLE[0].file_number=num_of_file;
	SYMBOL_TABLE[0].ENTRY_FLAG=0;
	strcpy(SYMBOL_TABLE[0].symbol_status,"NONE");
	

		if(WORD_TYPE==DATA){

			
			SYMBOL_TABLE[0].address=(*DC);
			strcpy(SYMBOL_TABLE[0].symbol_type,"DATA");
			}
	
		else{
			SYMBOL_TABLE[0].address=(*IC);
			strcpy(SYMBOL_TABLE[0].symbol_type,"CODE");
			}
return SYMBOL_TABLE;
	
	      }
	
return NULL;
}


