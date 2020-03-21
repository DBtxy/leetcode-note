#include<iostream>
#include<map>

using namespace std;


struct DoubleListNode {
	int key;
	int val;
	DoubleListNode *next, *former;
	DoubleListNode(int key, int val): val(val), key(key), next(NULL), former(NULL) {}
};


class LRUCache {
public:
	
    LRUCache(int capacity) {
        capacity = capacity;
    }
    
    int get(int key) {
		DoubleListNode *temp;
        if(mapper.find(key) != mapper.end()){
			temp = mapper[key];
			update(temp);
			return temp->val;
		}
		return -1;
    }
    
    void put(int key, int value) {
		if (mapper.find(key) != mapper.end()){
			update(mapper[key]);
		}
		else{
			if(mapper.size() == capacity){
				int deleteKey = RemoveLast();
				mapper.erase(deleteKey);
			}
			DoubleListNode *now = new DoubleListNode(key, value);
			now->next = head;
			if (head){
				head->former = now;
			}
			head = now;
			mapper[key] = now;
		}
    }
	
	void update(DoubleListNode *node){
		if (node == tail){
			tail = node->former;
		}
		node->next = head;
		head->former = node;
		head = node;
	}
	
	int RemoveLast(){
		int key = tail->key;
		DoubleListNode *temp = tail->former;
		if (temp) {
			temp->next = NULL;
			delete(tail);
			tail = NULL;
		}
		return key;
	}
	
private:
	int capacity;
	DoubleListNode *head, *tail;
	map<int, DoubleListNode*> mapper;
};

int main(){


}
