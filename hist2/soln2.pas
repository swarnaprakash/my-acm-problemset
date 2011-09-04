 {Submission by https://www.spoj.pl/KOPC09/users/khanhptnk/ during contest }
const fi='';
      fo='';
var   f,z:text;
      d,cnt:array [0..40100,0..20] of longint;
      h:array [0..20] of longint;
      n,i,kq1,kq2:longint;

{+++++++++++++++++++++++++++}

procedure lam;
var i,j,k,next,plus:longint;
begin
     for i:=1 to (1 shl n)-1 do
         for j:=1 to n do
             begin
                  d[i][j]:=-1;
                  cnt[i][j]:=0;
             end;

     for i:=1 to n do
         begin
              d[1 shl (i-1)][i]:=2*h[i]+1;
              cnt[1 shl (i-1)][i]:=1;
         end;

     for i:=1 to (1 shl n)-1 do
         for j:=1 to n do
             if (d[i][j]<>-1) then
                for k:=1 to n do
                    if ((i shr (k-1)) and 1=0) then
                       begin
                            next:=i xor (1 shl (k-1));

                            if (h[j]>h[k]) then
                               plus:=1
                            else
                                plus:=2*(h[k]-h[j])+1;

                            if (d[i][j]+plus>d[next][k]) then
                               begin
                                    d[next][k]:=d[i][j]+plus;
                                    cnt[next][k]:=cnt[i][j];
                               end
                            else
                                if (d[i][j]+plus=d[next][k]) then
                                        inc(cnt[next][k],cnt[i][j]);
                       end;

     kq1:=-maxlongint;
     kq2:=0;
     for i:=1 to n do
         if (d[(1 shl n)-1][i]>kq1) then
            begin
                 kq1:=d[(1 shl n)-1][i];
                 kq2:=cnt[(1 shl n)-1][i];
            end
         else
             if (d[(1 shl n)-1][i]=kq1) then
                inc(kq2,cnt[(1 shl n)-1][i]);
end;

{+++++++++++++++++++++++++++}

begin
     assign(f,fi);
     reset(f);
     assign(z,fo);
     rewrite(z);

     read(f,n);
     while (n>0) do
           begin
                for i:=1 to n do
                    read(f,h[i]);

                lam;
                writeln(z,kq1+n,' ',kq2);

                read(f,n);
           end;

     close(z);
     close(f);
end.
