import java.util.HashMap;
class Node {
    int key;
    int value;
    Node pre;
    Node next;
    
    public Node(int key, int value) {
        this.key = key;
        this.value = value;
    }
}

class LRUCache {
    int capacity, count;
    HashMap<Integer, Node> map;
    Node head, tail;

    public LRUCache(int capacity) {
        this.capacity=capacity;
        this.count=0;
        map = new HashMap<>();
        head = new Node(0,0);
        tail = new Node(0,0);
        head.next = tail;
        tail.pre = head;
        head.pre = null;
        tail.next = null;
    }

    public void deleteNode(Node node) {
        node.pre.next = node.next;
        node.next.pre = node.pre;
    }
    
    public void addToHead(Node node) {
        node.next = head.next;
        node.next.pre = node;
        node.pre = head;
        head.next = node;
    }
    
    public int get(int key) {
        if (map.get(key)==null){
            return -1;
        }
        Node node = map.get(key);
        deleteNode(node);
        addToHead(node);
        return node.value;
    }
    
    public void put(int key, int value) {
        if (map.get(key)==null) {
            Node node = new Node(key,value);
            map.put(key,node);
            if (count < capacity) {
                count++;
            } else {
                map.remove(tail.pre.key);
                deleteNode(tail.pre);
            }
            addToHead(node);
        } else {
            Node node = map.get(key);
            node.value = value;
            deleteNode(node);
            addToHead(node);
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */