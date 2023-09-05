class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Create a mapping to store the original nodes and their corresponding copied nodes.
        unordered_map<Node*, Node*> nodeMap;

        // Initialize a dummy node for the new linked list.
        Node* dummy = new Node(0);
        Node* current = dummy;

        Node* originalNode = head;

        // First Pass: Create a copy of each node without random pointers.
        while (originalNode) {
            // Create a new node with the same value as the original node.
            Node* copiedNode = new Node(originalNode->val);

            // Store the mapping between original and copied nodes.
            nodeMap[originalNode] = copiedNode;

            // Append the copied node to the new list.
            current->next = copiedNode;

            // Move to the next node in both the original and copied lists.
            originalNode = originalNode->next;
            current = current->next;
        }

        // Second Pass: Set random pointers for copied nodes using the mapping.
        originalNode = head; // Reset the original list pointer.
        current = dummy->next; // Reset the current pointer to the start of the copied list.

        while (originalNode) {
            // If the original node has a random pointer, set the copied node's random pointer
            // to the corresponding copied node using the mapping.
            if (originalNode->random) {
                current->random = nodeMap[originalNode->random];
            }

            // Move to the next nodes in both the original and copied lists.
            originalNode = originalNode->next;
            current = current->next;
        }

        // Return the head of the copied list (excluding the dummy node).
        return dummy->next;
    }
};
