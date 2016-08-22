#include<bits/stdc++.h>

using namespace std;
struct node
{
  char s;
  node *next;
};
void push(node *&s,char i)
{
  node*temp;
  node*newNode=new node;
  newNode->s=i;
  newNode->next=NULL;
  if(s==NULL)
  {
    s=newNode;
  }
  else
  {
    temp=s;
    s=newNode;
    newNode->next=temp;
  }
}
node* pop(node*&s)
{
  node*rtrn=new node;
  node*temp;
  if(s==NULL)
  return NULL;
  else
  {
    temp=s;
    s=s->next;
    rtrn=temp;
    rtrn->s=temp->s;
    rtrn->next=NULL;

    return rtrn;
  }
}

void printStack(node*s)
{
  cout<<"\n";
  while(s!=NULL)
  {
    cout<<"->"<<s->s;
    s=s->next;
  }
}


int main()
{
  char parse;
  int length,i=0;
  string expression;//input for infix form
  vector<char> postfix;//stores the final postfix expression
  map<char,int>precedence;
  node* s=NULL,*temp;
  //precedence declaration using map
  precedence['-']=1;
  precedence['+']=1;
  precedence['/']=2;
  precedence['*']=3;
  precedence['^']=4;
  cout<<"Expression:";
  getline(cin,expression);
  length=expression.length();

  while(i<length)
  {
    parse=expression[i];

    if(parse=='(')
    {
      push(s,parse);
    }
    else
    if(isalpha(parse)||isdigit(parse))//all digits and variable is printed
    {
      postfix.push_back(parse);

    }
    else
    if(parse==')')
    {
      temp=pop(s);
      while(temp!=NULL)
      {
        if(temp->s=='(')
          break;
        else
        {
          postfix.push_back(temp->s);
          temp=pop(s);
        }
      }
    }
    else
    if(parse=='*'||parse=='/'||parse=='+'||parse=='-'||parse=='^')
    {
      temp=pop(s);
      while(temp!=NULL)
      {
          if(precedence[temp->s]<precedence[parse])//if the top of the stack has lower precedence push
          {
            push(s,temp->s);
            push(s,parse);
            break;
          }
          else
          if(precedence[temp->s]>=precedence[parse])//else we pop it and store in postfix
          {                                               //then we check with the next stack element
            postfix.push_back(temp->s);
            temp=pop(s);
          }
      }
      if(temp==NULL)//if for the above case the stack becomes empty we just push
      {
        push(s,parse);
      }
    }
    i+=1;
    printStack(s);
    int l;
    cin>>l;
  }

  while(s!=NULL)
  {
    temp=pop(s);
    postfix.push_back(temp->s);
  }
  cout<<endl<<"postfix:";
  for (std::vector<char>::iterator it = postfix.begin() ; it != postfix.end(); ++it)
    std::cout <<*it;
  return 0;
}
