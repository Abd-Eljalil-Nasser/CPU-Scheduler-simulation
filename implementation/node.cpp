#include"Node.h"
 Node::Node(int id, int start, int end){
     this->ProcessId = id;
     this->start = start;
     this->end = end;
}
 Node::Node() {
     this->ProcessId = 0;
     this->start = 0;
     this->end = 0;
 }
 void Node::set_ProcessId(int id) {
     this->ProcessId = id;
 }
 int Node::get_ProcessId() {
     return this->ProcessId;
 }
 void Node::set_start(int start) {
     this->start = start;
 }
 int Node::get_start() {
     return this->start;
 }
 void  Node::set_end(int end) {
     this->end = end;
 }
 int Node::get_end()
 {
     return this->end;
 }

