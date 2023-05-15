class extended_linked_list {};

class exclusive_linked_list_node {
 public:
  void * value_pointer;
  exclusive_linked_list_node * back = nullptr;
  exclusive_linked_list_node * forward = nullptr;
  extended_linked_list * extended_linked_list_reference = nullptr;
};

class extended_linked_list {
 private: 
  void destroy_node(exclusive_linked_list_node * node)
  {
   delete node->back;
   delete node->forward;
   delete node->extended_linked_list_reference;
  }
 public:
  int linked_list_size = 0;

  exclusive_linked_list_node * end = nullptr;
  exclusive_linked_list_node * start = nullptr;
 
  void insert_new_node (exclusive_linked_list_node * new_node)
  {
   new_node->extended_linked_list_reference = this;
   if (this->linked_list_size == 0)
   {
     this->start = new_node;
     this->end = new_node;
     this->linked_list_size++;
     return;
   };
   this->linked_list_size++;
   this->end->forward = new_node;
   new_node->back = this->end;
   this->end = new_node;
   return;
  };

  void remove_old_node (exclusive_linked_list_node * node)
  {
   if (this->linked_list_size == 0)
   {
    return;
   }
   else if (this->linked_list_size == 1) {
    this->start = nullptr;
    this->linked_list_size--;
    return;
   }
   else if (this->linked_list_size == 2)
   {
    if(node == this->start)
    {
     this->end->back = nullptr;
     this->start = this->end;   
    }
    else {
     this->start->forward = nullptr;
     this->end = this->start;   
    }
    this->linked_list_size--;
    return;
   }

   if (node == this->end)
   {
    this->end = node->back;
   }
   else if (node == this->start)
   {
    this->start = node->forward;
   }

   node->back->forward = node->forward;
   node->forward->back = node->back;
   //since the you are handling the node, there is no need for garbage collection.
  }

  void pop (exclusive_linked_list_node * return_ptr) 
  {
   exclusive_linked_list_node * end = this->end; 
   remove_old_node(end);
   return_ptr = end;
   delete end;
  }

  void destroy () //cleans every reference in the linked_list
  {
    exclusive_linked_list_node * previous_node = nullptr;
    exclusive_linked_list_node * current_node = this->start;

    while (true)
    {
     this->destroy_node(previous_node);
     if (current_node == nullptr)
     {
      break;  
     }
     previous_node = current_node;
     current_node = current_node->forward;
    } 

    this->linked_list_size = 0;
    delete this->end;
    delete this->start;
    delete this;
  }
};

class linked_list_node {
 linked_list_node * next;
 void * value_pointer;
};