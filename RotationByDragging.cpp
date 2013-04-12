void DraggingOperation(Mouse event)
{
	/*
	 * prevx and prevy are updated everytime the mouse is pressed down, not while it's pressed
	 */
	if (isDragging == true)
    {
		// get mouse's coordinates
        int x = event.GetX();
        int y = event.GetY();

		// get client's window size
        int w = 0, h = 0;
        GetClientSize(&w, &h);

        float xangle = (prevy - y) * 360.0f / w;
        float yangle = (x- prevx) * 360.0f / h;

        sth->rotX(xangle);
        sth->rotY(yangle);

        prevx = x;
        prevy = y;

        Refresh();
    }
}
