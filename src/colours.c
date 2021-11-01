int	create_trgb(int transp, int red, int green, int blue)
{
	return (transp << 24 | red << 16 | green << 8 | blue);
}

int	get_transparancy(int trgb)
{
	return (trgb & (0xFF << 24));
}

int	get_red(int trgb)
{
	return (trgb & (0xFF << 16));
}

int	get_green(int trgb)
{
	return (trgb & (0xFF << 8));
}

int	get_blue(int trgb)
{
	return (trgb & 0xFF);
}

int	get_invert(int colour)
{
	return ((colour ^ 0xFF));
}
