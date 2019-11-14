//
//  DB.h
//  Project4
//
//  Created by Jiangyong Xu on 11/13/19.
//  Copyright © 2019 Jiangyong Xu. All rights reserved.
//

#ifndef DB_h
#define DB_h


#define SIZE 1009

typedef struct CSG CSG;

struct CSG* CSG_DB[SIZE];     //initializing a hashtable with size SIZE

extern int hash(int key);

struct CSG *lookup(char *course, char *studentID, char *grade );      //lookup

void insert(int key, CSG tuple);

struct CSG* delete(struct CSG* item);

#endif /* hashTable_h */

