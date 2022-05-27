void forward()
{
  swing(x1, y2, Z_rest);
    
  delay(d_time);
    
  for(X=x1; X>=x2; X--)
  {
    swing_2D(X, y2, Z_rest);
  }

  delay(d_time);
    
  for(Y=y2; Y<=y3; Y++)
  {
    swing_2D(x2, Y, Z_rest);
  }

  delay(d_time);

  for(X=x2; X<x_mid; X++)
  {    
    swing_2D(X, y3, Z_rest);
  }

  delay(d_time);

  for(X=50; X<100; X++)
  {
    Y=-dydx*X+Y_rest+y_offset;
    swing_2D(X, Y, Z_rest);
  }
}
