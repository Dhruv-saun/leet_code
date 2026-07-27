class Solution {
    public String removeDuplicates(String s) {
        Stack<Character> stack= new Stack<>();
        for(char ch: s.toCharArray())
        {
            if(!stack.isEmpty()&&stack.peek()==ch)
            {
                stack.pop();
            }
            else{
                stack.push(ch);
            }
        }
        String t="";
        while(!stack.isEmpty()){
            t+=stack.peek();
            stack.pop();
        }
        String reversed = new StringBuilder(t).reverse().toString();
        return reversed;
    }
}