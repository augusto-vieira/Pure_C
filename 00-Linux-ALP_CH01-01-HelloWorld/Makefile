-include config.mk

app: $(OBJ_C) $(OBJ_CPP)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.c
	@echo "compiling $@" 
	$(CC) -c $(CFLAGS) $^ -o $@

%o: %.cpp	
	$(CXX) -c $(CPPFLAGS) $^ -o $@
	@echo "compiling $^"

clean:
	$(RM)  *.o app	

info:
	@echo "SRC_C = $(SRC_C)" 
	@echo "SRC_CPP = $(SRC_CPP)" 
