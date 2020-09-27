#ifndef NODE_H
#define NODE_H
class Node{
private:
    int ProcessId;
    int start;
    int end;
public:
    Node(int id, int start, int end);
    Node();
    void set_ProcessId(int id);
    int get_ProcessId();
    void set_start(int start);
    int get_start();
    void set_end(int end);
    int get_end();
};
#endif // NODE_H
