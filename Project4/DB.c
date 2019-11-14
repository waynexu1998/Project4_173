//
//  hashTable.c
//  Project4
//
//  Created by Jiangyong Xu on 11/13/19.
//  Copyright © 2019 Jiangyong Xu. All rights reserved.
//

#include "DB.h"
#include <stdio.h>
#include <stdlib.h>

int hash(int key){
    return key%SIZE;
}

typedef struct CSG{   //CSG structure
    char course[5];
    int studentID;
    char grade[2];
    CSG *next;
}CSG;



void insert(int key, CSG tuple){
    int index = hash(key);
    if(CSG_DB[index] == NULL){
        *CSG_DB[index] = tuple;
    }else{
        if(CSG_DB[index]->next != NULL){
            *CSG_DB[index]->next->next = tuple;
        }else{
            *CSG_DB[index]->next = tuple;
        }
    }
}


struct CSG *lookup(char *course, char *studentID, char *grade){      //hash table lookkup
    int id = atoi(studentID);                       //integer value of studentID
    CSG* outputCSG[SIZE];
    int arrayCount = 0;
    if(course[0] == '*' && studentID[0] =='*'){     //course and studentID '*'
        for (int i=0; i<SIZE; i++) {
            if(CSG_DB[i]->grade == grade){
                outputCSG[arrayCount++] = CSG_DB[i];
            }
        }
    }else if (course[0] == '*' && grade[0] == '*'){ //course and grade '*'
        for (int i=0; i<SIZE; i++) {
            if (CSG_DB[i]->studentID == id) {
                outputCSG[arrayCount++] = CSG_DB[i];
            }
        }
    }else if (studentID[0] == '*' && grade[0] =='*'){  //studentID and grade '*'
        for (int i=0; i<SIZE; i++) {
            if(CSG_DB[i]->course == course){
                outputCSG[arrayCount++] = CSG_DB[i];
            }
        }
    }else if (course[0] == '*') {                                             //course left as '*'
        for(int i=0; i<SIZE; i++){
            if (CSG_DB[i]->studentID == id && CSG_DB[i]->grade == grade) {
                outputCSG[arrayCount++] = CSG_DB[i];
            }
        }
    }else if (studentID[0] == '*'){                                     //studentID left as '*'
        for (int i=0; i<SIZE; i++) {
            if (CSG_DB[i]->course == course && CSG_DB[i]->grade == grade) {
                outputCSG[arrayCount++] = CSG_DB[i];
            }
        }
    }else if (grade[0] == '*'){                                         //grade left as '*'
        for (int i=0; i<SIZE; i++) {
            if (CSG_DB[i]->course == course && CSG_DB[i]->studentID == id) {
                outputCSG[arrayCount++] = CSG_DB[i];
            }
        }
    }
    return *outputCSG;
}
