/* 
 * File:   bankmapper.h
 * Author: damien
 */

#ifndef BANKMAPPER_H
#define	BANKMAPPER_H

class bankmapper {
public:
    bankmapper();
    bankmapper(const bankmapper& orig);
    virtual ~bankmapper();
    void init(char*, char*, int);
    char* address;
    int bid;
    char* name;
};

#endif	/* BANKMAPPER_H */