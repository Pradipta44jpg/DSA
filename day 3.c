#define MAX 10000

struct TreeNode* queue[MAX];
int front = -1;
int rear  = -1;

void enqueue(struct TreeNode *node){
    if (front == -1)
        front = 0;
    queue[++rear] = node;
}

struct TreeNode* dequeue() {
    return queue[front++];
}

int minDepth(struct TreeNode* root) {
    front = rear = -1;     // ✅ reset for each test case

    if (root == NULL) return 0;

    enqueue(root);
    int depth = 1;

    while (front <= rear) {
        int size = rear - front + 1;

        for (int i = 0; i < size; i++) {
            struct TreeNode* cur = dequeue();

            if (cur->left == NULL && cur->right == NULL)
                return depth;

            if (cur->left)
                enqueue(cur->left);
            if (cur->right)
                enqueue(cur->right);
        }
        depth++;
    }
    return depth;
}
