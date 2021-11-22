include Makefile.variable
LIBFT = $(LIBFTDIR)/$(LIBFTNAME)
LIBPRINTF = $(PRINTFDIR)/$(LIBPRINTFNAME)
LIBGNL = $(GNLDIR)/$(LIBGNLNAME)

$(MYLIBNAME): $(LIBFT) $(LIBPRINTF) $(LIBGNL)
	ar -rs $(MYLIBNAME) *.o
	make clean
$(LIBFT): $(LIBFTDIR)/*.c $(LIBFTDIR)/*.h
	$(MAKE) --directory=$(LIBFTDIR)
	cp $(LIBFT) .
	ar -x $(LIBFTNAME)
	rm -f $(LIBFTNAME)
$(LIBPRINTF): $(PRINTFDIR)/*.c $(PRINTFDIR)/*.h
	$(MAKE) --directory=$(PRINTFDIR)
	cp $(LIBPRINTF) .
	ar -x $(LIBPRINTFNAME)
	rm -f $(LIBPRINTFNAME)
$(LIBGNL): $(GNLDIR)/*.c $(GNLDIR)/*.h
	$(MAKE) --directory=$(GNLDIR)
	cp $(LIBGNL) .
	ar -x $(LIBGNLNAME)
	rm -f $(LIBGNLNAME)
.PHONY: all fclean fcleanall
all: $(MYLIBNAME)
clean:
	rm -rf *.o __.SYMDEF __.SYMDEF\ SORTED
fclean:
	make clean
	rm -rf $(MYLIBNAME)
	rm -f $(LIBFT) $(LIBPRINTF) $(LIBGNL)
fcleanall: fclean
	$(MAKE) fcleanall --directory=$(LIBFTDIR)
	$(MAKE) fcleanall --directory=$(GNLDIR)
	$(MAKE) fcleanall --directory=$(PRINTFDIR)
