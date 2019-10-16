/*
设计一个最大栈，支持 push、pop、top、peekMax 和 popMax 操作。

push(x) -- 将元素 x 压入栈中。
pop() -- 移除栈顶元素并返回这个值。
top() -- 返回栈顶元素。
peekMax() -- 返回栈中最大元素。
popMax() -- 返回栈中最大的元素，并将其删除。如果有多个最大元素，只要删除最靠近栈顶的那个。
 

样例 1:

MaxStack stack = new MaxStack();
stack.push(5); 
stack.push(1);
stack.push(5);
stack.top(); -> 5
stack.popMax(); -> 5
stack.top(); -> 1
stack.peekMax(); -> 5
stack.pop(); -> 1
stack.top(); -> 5
 

注释:

-1e7 <= x <= 1e7
操作次数不会超过 10000。
当栈为空的时候不会出现后四个操作。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-stack
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
typedef struct node
{
    int value;
    struct node *next;
} MaxStack;

/** initialize your data structure here. */

MaxStack *maxStackCreate()
{
    MaxStack *head = (MaxStack *)malloc(sizeof(MaxStack));
    if (head == NULL)
    {
        return NULL;
    }
    head->next = NULL;
    return head;
}

void maxStackPush(MaxStack *obj, int x)
{
    MaxStack *node = (MaxStack *)malloc(sizeof(MaxStack));
    node->value = x;
    node->next = obj->next;
    obj->next = node;
}

int maxStackPop(MaxStack *obj)
{
    if (obj->next == NULL)
    {
        return -1;
    }
    MaxStack *tmp = obj->next;
    int rslt = tmp->value;
    obj->next = tmp->next;
    tmp->next = NULL;
    free(tmp);
    tmp = NULL;
    return rslt;
}

int maxStackTop(MaxStack *obj)
{
    if (obj->next == NULL)
    {
        return -1;
    }
    return obj->next->value;
}

int maxStackPeekMax(MaxStack *obj)
{        
    int max;
    MaxStack *tmp = obj->next;
    if(tmp != NULL) {
        max = tmp->value;
    }
    while (tmp != NULL)
    {
        if (tmp->value > max)
        {
            max = tmp->value;
        }
        tmp = tmp->next;
    }
    return max;
}
int maxStackPopMax(MaxStack *obj)
{
    int max = maxStackPeekMax(obj);
    
    MaxStack *pre = obj;
    MaxStack *tmp = obj->next;

    while (tmp != NULL)
    {
        if (tmp->value == max)
        {
            pre->next = tmp->next;
            free(tmp);
            tmp = NULL;
            return max;
        }
        pre = tmp;
        tmp = tmp->next;
    }
    return max;
}
void maxStackFree(MaxStack *obj)
{
    MaxStack *tmp;
    while(obj != NULL) {
        tmp = obj;
        obj = obj->next;
        free(tmp);
    }
    tmp = NULL;
}
/**
 * Your MaxStack struct will be instantiated and called as such:
 * MaxStack* obj = maxStackCreate();
 * maxStackPush(obj, x);
 
 * int param_2 = maxStackPop(obj);
 
 * int param_3 = maxStackTop(obj);
 
 * int param_4 = maxStackPeekMax(obj);
 
 * int param_5 = maxStackPopMax(obj);
 
 * maxStackFree(obj);
*/
/*
int main()
{
    MaxStack *obj = maxStackCreate();
    maxStackPush(obj, 1);
    maxStackPush(obj, 3);
    maxStackPush(obj, 10);
    maxStackPush(obj, 6);
    maxStackPush(obj, 10);
    maxStackPush(obj, 2);

    printf("%d\n",maxStackPeekMax(obj));
    printf("=====================\n");
    //printf("%d\n",maxStackPop(obj));
    //printf("%d\n",maxStackPop(obj));
    printf("%d\n",maxStackPop(obj));
    printf("%d\n",maxStackTop(obj));
    printf("=====================\n");
    //maxStackFree(obj);
    printf("%d\n",maxStackPopMax(obj));
    printf("=====================\n");

    MaxStack *tmp = obj->next;
    while(tmp->next != NULL) {
        printf("%d\t", tmp->value);
        tmp = tmp->next;
    }
    printf("%d\n", tmp->value);
    maxStackFree(obj);
    return 0;
}
*/
