#ifndef TP4_GRAPH_LIST_H
#define TP4_GRAPH_LIST_H

#include <list>

template<class T>
class GraphList {
public:
    /**
     * Adds a node to the main list.
     * @param e
     * @return data
     */
    GraphList &addNode(T e) {
        data.push_back({e});
        return *this;
    }

    /**
     * Links two nodes and if the 'to' node is not present in the main list it creates it.
     * @param f
     * @param t
     */
    void addEdge(T f, T t) { // f = from ; t = to
        typename std::list<std::list<T>>::iterator nested_list_itr;
        // If exists in the first of the inner lists.
        bool tExistsInMain = false;
        for(nested_list_itr = data.begin(); nested_list_itr != data.end(); ++nested_list_itr) {
            typename std::list<T>::iterator single_list_itr;
            std::list<T>& single_list_pointer = *nested_list_itr;

            for(single_list_itr = single_list_pointer.begin(); single_list_itr != single_list_pointer.end(); single_list_itr++) {
                if(single_list_pointer.front() == f) {
                    single_list_pointer.push_back(t);
                    break;
                }
            }
            for(single_list_itr = single_list_pointer.begin(); single_list_itr != single_list_pointer.end(); single_list_itr++) {
                if (single_list_pointer.front() == t) tExistsInMain = true;
            }
        }
        if(!tExistsInMain) addNode(t);
    }

    /**
     * Checks if two nodes are connected.
     * @param f
     * @param t
     * @return
     */
    bool isConnected(T f, T t) {
        for(std::list<T> innerList: data) {
            if(innerList.front() == f) {
                for(T element: innerList) {
                    if(element == t) return true;
                }
            }
        }
        return false;
    }

    /**
     * Prints all the lists.
     */
    void print() {
        int i1 = 0;
        std::cout << "[ " << std::endl;
        for(std::list<T> innerList: data) {
            std::cout << "   [";
            int j1 = 0;
            for(T element: innerList) {
                std::cout << element << ((innerList.size() > (j1+1)) ? ", " : "");
                j1++;
            }
            std::cout << "]" << ((data.size() > i1+1) ? "," : "") << std::endl;
            i1++;
        }
        std::cout << "]" << std::endl;
    }
private:
    std::list<std::list<T>> data;
};

#endif //TP4_GRAPH_LIST_H
