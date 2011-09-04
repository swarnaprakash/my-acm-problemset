{submission by https://www.spoj.pl/KOPC09/users/billwsy/ during contest }
var i,j,k,x,n,m,q:longint;
    t:array[1..300000]of longint;
    c:char;
function max(x,y:longint):Longint;
   begin
      if x>y then exit(x);
      exit(y);
   end;
procedure update(p,l,r:longint);
   var mid:longint;
   begin
      if l<r then
      begin
         mid:=(l+r)shr 1;
         if k<=mid
            then update(p+p,l,mid)
            else update(p+p+1,mid+1,r);
         t[p]:=max(t[p+p],t[p+p+1]);
      end else t[p]:=x;
   end;
function gax(p,l,r,tl,tr:longint):longint;
   var mid:longint;
   begin
      if tl>tr then exit(-1);
      if (tl<=l)and(tr>=r)then exit(t[p]);
      mid:=(l+r)shr 1;
      if tl<=mid then gax:=gax(p+p,l,mid,tl,tr) else gax:=-1;
      if tr>mid then gax:=max(gax,gax(p+p+1,mid+1,r,tl,tr));
   end;
function pos(p,l,r,tl,tr:longint):longint;
   var mid:longint;
   begin
      mid:=(l+r)shr 1;
      if (tl<=l)and(tr>=r) then
      begin
         if l=r then exit(l);
         if t[p+p]=x
            then exit(pos(p+p,l,mid,tl,tr))
            else exit(pos(p+p+1,mid+1,r,tl,tr));
      end;
      pos:=-1;
      if (tl<=mid)and(t[p+p]>=x)then pos:=pos(p+p,l,mid,tl,tr);
      if (tr>mid)and(t[p+p+1]>=x)then pos:=max(pos,pos(p+p+1,mid+1,r,tl,tr));
   end;
function query(l,r:longint):longint;
   var z:longint;
   begin
      x:=gax(1,1,n,l,r);
      z:=pos(1,1,n,l,r);
      exit(x+max(gax(1,1,n,l,z-1),gax(1,1,n,z+1,r)));
   end;
begin
   readln(n);
   for k:=1 to n do
   begin
      read(x);
      update(1,1,n);
   end;
   readln(q);
   for i:=1 to q do
   begin
      readln(c,k,x);
      if c='Q'
         then writeln(query(k,x))
         else update(1,1,n);
   end;
end.