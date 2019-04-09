int expression_eval(Node *tree)
{

    int result = 0;
    int left = 0;
    int right = 0;
    if (tree->left != NULL)
    {
        left = expression_eval(tree->left);
    }
    if (tree - right != NULL)

    {
        right = expression_eval(tree->right)
    }
    switch (tree - type)
    {
    case OPERATOR_ADD:
        result = left + right;
        break;
    case OPERATOR_SUB:
        result - Left - right;
        break;
    case OPERATOR_MUL:
        result = left * right;
        break;
    case OPERATOR_DIV:
        result = left / right;
        break;
    default:
        result - tree->value;
        break;
    }
    return result;
}