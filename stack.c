#ifndef STACK_C
#define STACK_C
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>


// items
struct node{
	int _data;
	struct node* _next;
};

// container struct
struct _stack{
	struct node* _head;
	unsigned long _size;
};



//creating a stack 
struct _stack* initStack()
{
	struct _stack* newEl = (struct _stack*)malloc(sizeof(struct _stack));
	newEl->_head = NULL;
	newEl->_size = 0;
	return newEl;
}


// func to allocate item
struct node* alloc(){
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->_next = NULL;
	return new_node;
}

void push(struct _stack* st, int val)
{
	// in case of empty stack
	if(st->_head==NULL)
	{
		st->_head = alloc();
		st->_head->_data = val;		
		st->_size++;
		return;
	}
	struct node* _iterator = st->_head;
	while(_iterator->_next!=NULL)
	{
		_iterator = _iterator->_next;
	}
	_iterator->_next = alloc();
	_iterator->_next->_data = val;
	st->_size++;
	return;
}

void pop(struct _stack* st)
{
	if(st->_head!=NULL)
	{
		struct node* _iterator=st->_head;
		struct node* _prev = _iterator;
		while(_iterator->_next!=NULL)
		{
			_prev = _iterator;
			_iterator = _iterator->_next;
		}
		if(_iterator==st->_head){
			free(_iterator);
			st->_head = NULL;
			st->_size = 0;
			return;
		}
		free(_iterator);
		_prev->_next = NULL;
		st->_size--;	
	}
	return;
}

int _top(struct _stack* st){ // return a top element on the stack
	if(st->_head!=NULL){
	struct node* _iterator = st->_head;
	while(_iterator->_next!=NULL){
		_iterator=_iterator->_next;
	}
	return _iterator->_data;
	}
}

int isEmpty(struct _stack* st)
{
	return st->_head==NULL && st->_size==0;
}

void clear(struct _stack* st){
	while(!isEmpty(st)) pop(st);	
}
void destroy(struct _stack*& st){ // clearing stack
	clear(st);
	free(st);
}

#endif
