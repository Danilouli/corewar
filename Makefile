# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acouturi <acouturi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 17:18:12 by fsabatie          #+#    #+#              #
#    Updated: 2018/04/05 22:19:14 by acouturi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re peace asm vm dasm

# Defining colors

RED		= \033[1;31m
GREEN	= \033[0;32m
ORANGE	= \033[0;33m
BLUE	= \033[1;36m
YELLOW	= \033[1;33m
PURPLE	= \033[1;35m
RESET	= \033[0m

# Defining paths

LIB_PATH = libft
DASM_PATH = ddasm
ASM_PATH = asm
VM_PATH = vm

# Defining rules

all: lib dasm asm vm

lib:
	@make -C $(LIB_PATH)

dasm: lib
	@make -C $(DASM_PATH)
	@mv ./ddasm/dasm .

asm:
	@make -C $(ASM_PATH)

vm:
	@make -C $(VM_PATH)

clean:
	@make clean -C $(DASM_PATH)
	@make clean -C $(LIB_PATH)
	@make clean -C $(ASM_PATH)
	@make clean -C $(VM_PATH)

fclean:
	@make fclean -C $(DASM_PATH)
	@make fclean -C $(LIB_PATH)
	@make fclean -C $(ASM_PATH)
	@make fclean -C $(VM_PATH)
	@rm dasm

peace:
	@clear;
	@echo "$(GREEN)"
	@echo "                                                 ."
	@echo "                                                 :\`"
	@echo "                                                 ++"
	@echo "                                                .ss:"
	@echo "                                                +yys."
	@echo "                                               -yyys/                   \`"
	@echo "                            \`                  oyyyso                 .:"
	@echo "                             -/-\`             .syyyys.             \`:o/"
	@echo "                              \`oyo:\`          :yyyyys:           :oyyo"
	@echo "                               .syyso-\`       +yyyyys/        -+syyyo\`"
	@echo "                                \`oyyyys/\`    \`syyyyss:     ./syyyyyo\`"
	@echo "                                 \`oyyyyys:   .yyyyyss:   \`/yyyyyyso\`"
	@echo "                                  \`oyyyyyyo. .yyyyyss-  -yyyyyyss+"
	@echo "                                   \`+yyyyyyy- +yyyyss\`\`+yyyyysss/\`"
	@echo "                                     -syyyyyy-.syyys/.oyyyyyss+."
	@echo "                                       -oyyyys\`-yyyo.syyyyss/."
	@echo "                          \`.-/+//:/::-.\` \`-+yyo :yo.oyyso:-\`.-:/++ooso/:.\`"
	@echo "                              ./oyyyyyyyso/-\`.// o.++-..:+osyyyyyys+-"
	@echo "                                 \`./+ossyysss+::://-:ossyyyyyyso/."
	@echo "                                         \`./+os:\`.:so++/:-.-\`\`"
	@echo "                                      \`-oyys/-\` \`. \`:oyhhy+-"
	@echo "                                    \`:+/:.\`     .\`     ./ooys:\`"
	@echo "                                   \`-           .           \`./:"
	@echo "                                                -               \`"
	@echo "                                                -"
	@echo "                                                -"