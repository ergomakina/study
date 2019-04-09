for (i = 0; i < n;)
{
    len = write(fd, buf + i, n - i);
    i += len;
}