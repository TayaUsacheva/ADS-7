// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <iostream>
#include <string>
template<typename T>
class TPQueue {
  // реализация шаблона очереди с приоритетом на связанном списке
  
  private:
      struct Item {
        T DATA;
        Item* next;
        Item* prev;
    };
    Item* head = nullptr;
    Item* tail = nullptr;
    TPQueue::Item* create(const T& data) {
        Item* temp = new Item;
        temp->DATA = data;
        temp->next = nullptr;
        temp->prev = nullptr;
        return temp;
    }
  
 public:
    bool isEmpty() {
      return head == nullptr;
    }
   T pop() {
        if (isEmpty()) {
            throw std::string("It is empty");
        }
        Item* temp = head->next;
        T n;
        if (temp) {
            temp->prev = nullptr;
            n = head->DATA;
            delete head;
            head = temp;
        } else {
            n = head->DATA;
            delete head;
            head = tail = nullptr;
        }
        return n;
    }
    void push(const T& data) {
        if (isEmpty()) {
            head = tail = create(data);
        } else {
            Item* t = head;
            Item* item = create(data);
            while (t && t->DATA.prior >= DATA.prior)
                t = t->next;
            if (!t && head) {// в конец
                tail->next = item;
                tail->next->prev = tail;
                tail = item;
            } else if (!t && !head) {// в пустой список
                head = tail = item;
            } else if (!t->prev) {// в начало
                t->prev = item;
                item->next = t;
                head = item;
            } else {// в середину
                t->prev->next = item;
                item->prev = t->prev;
                item->next = t;
                t->prev = item;
            }
        }
    }
};

struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
