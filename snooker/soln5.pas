 {submission by https://www.spoj.pl/KOPC09/users/foreverleer/ during contest}
var
    h1,h2,h3,h4:array[0..200005] of boolean;
    x,y,k,n,m,ans,cases,t:longint;
function min(a,b:longint):longint;
begin
    min:=a; if a>b then min:=b;
end;

procedure calc(var x,y,k:longint);
var
    t:longint;
begin
    if k=1 then
    begin
        t:=min(n-x,y); inc(x,t); dec(y,t);
        if x=n then k:=4 else k:=2;
    end
    else if k=2 then
    begin
        t:=min(n-x,m-y); inc(x,t); inc(y,t);
        if x=n then k:=3 else k:=1;
    end
    else if k=3 then
    begin
        t:=min(x,m-y); dec(x,t); inc(y,t);
        if y=m then k:=4 else k:=2;
    end
    else if k=4 then
    begin
        t:=min(x,y); dec(x,t); dec(y,t);
        if x=0 then k:=1 else k:=3;
    end;
end;

function ok(x,y:longint):boolean;
begin
    ok:=true;
    if (x=0) and (y=0) or (x=0) and (y=m) or (x=n) and (y=0) or (x=n) and (y=m) then exit(false);
    if (x=0) then
    begin
        if h1[x+y]=true then exit(false) ;
        h1[x+y]:=true;
    end
    else if x=n then
    begin
        if h2[x+y]=true then exit(false);
        h2[x+y]:=true;
    end
    else if (y=0)  then
    begin
        if h3[x+y]=true then exit(false);
        h3[x+y]:=true;
    end
    else if (y=m) then
    begin
        if h4[x+y]=true then exit(false);
        h4[x+y]:=true;
    end;
end;

procedure doit(x,y,k:longint);
begin
    fillchar(h1,sizeof(h1),0);
    fillchar(h2,sizeof(h2),0);
    fillchar(h3,sizeof(h3),0);
    fillchar(h4,sizeof(h4),0);
    calc(x,y,k);
    while ok(x,y) do
    begin
        inc(ans);
        calc(x,y,k);
        t:=1;
    end;
end;

begin

    readln(m,n);
    while (n<>0) and (m<>0) do
    begin
        inc(cases); if cases<>1 then writeln;
        ans:=0;
        doit(0,m,1);
        //doit(0,0,2);
        //doit(n,0,3);
        //doit(n,m,4);
        write(ans*4);
        readln(m,n);
    end;
end.
